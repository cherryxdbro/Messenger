#include "pch.h"

#include "ServerPage.h"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Messenger::implementation
{
	Windows::Networking::Sockets::StreamSocketListener ServerPage::streamSocketListener;
	Windows::Networking::Sockets::StreamSocket ServerPage::streamSocket;

	ServerPage::ServerPage() :
		m_clientNetworkActionViewModel(make<Messenger::implementation::NetworkActionViewModel>()),
		m_serverNetworkActionViewModel(make<Messenger::implementation::NetworkActionViewModel>())
	{

	}

	void ServerPage::OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs const& e) const
	{
		__super::OnNavigatedTo(e);
		Frame().IsEnabled(true);
	}

	void ServerPage::BackButton_Click(IInspectable const&, RoutedEventArgs const&) const
	{
		Frame().IsEnabled(false);
		Frame().GoBack();
	}

	void ServerPage::ServerMenuButton_Click(IInspectable const&, RoutedEventArgs const&)
	{
		ServerMenuButton().Flyout(ServerMenuFlyout());
	}

	void ServerPage::StartServerButton_Click(IInspectable const&, RoutedEventArgs const&)
	{
		StartServerButton().IsEnabled(false);
		StartServer();
		StartClient();
	}

	void ServerPage::AddVLANButton_Click(IInspectable const&, RoutedEventArgs const&)
	{

	}

	Messenger::NetworkActionViewModel ServerPage::ClientNetworkActionViewModel()
	{
		return m_clientNetworkActionViewModel;
	}

	Messenger::NetworkActionViewModel ServerPage::ServerNetworkActionViewModel()
	{
		return m_serverNetworkActionViewModel;
	}

	Windows::Foundation::IAsyncAction ServerPage::OnConnectionReceived(Windows::Networking::Sockets::StreamSocketListener const&, Windows::Networking::Sockets::StreamSocketListenerConnectionReceivedEventArgs const& args)
	{
		try
		{
			Windows::Networking::Sockets::StreamSocket socket{ args.Socket() };
			Windows::Storage::Streams::DataReader dataReader{ socket.InputStream() };
			unsigned int bytesLoaded = co_await dataReader.LoadAsync(sizeof(unsigned int));
			unsigned int stringLength = dataReader.ReadUInt32();
			bytesLoaded = co_await dataReader.LoadAsync(stringLength);
			hstring request = dataReader.ReadString(bytesLoaded);
			serverListBox().Dispatcher().RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal, [=]()
				{
					std::wstringstream wstringstream;
					wstringstream << L"server received the request: \"" << request.c_str() << L"\"";
					serverListBox().Items().Append(box_value(wstringstream.str().c_str()));
				});
			Windows::Storage::Streams::DataWriter dataWriter{ socket.OutputStream() };
			dataWriter.WriteUInt32(request.size());
			dataWriter.WriteString(request);
			co_await dataWriter.StoreAsync();
			dataWriter.DetachStream();
			serverListBox().Dispatcher().RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal, [=]()
				{
					std::wstringstream wstringstream;
					wstringstream << L"server sent back the response: \"" << request.c_str() << L"\"";
					serverListBox().Items().Append(box_value(wstringstream.str().c_str()));
				});
			streamSocketListener = nullptr;
			serverListBox().Dispatcher().RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal, [=]()
				{
					serverListBox().Items().Append(box_value(L"server closed its socket"));
				});

		}
		catch (hresult_error const& error)
		{

		}
	}

	Windows::Foundation::IAsyncAction ServerPage::StartServer()
	{
		try
		{
			int portNumber = std::stoi(to_string(ServerPortTextBox().Text()));
			if (portNumber < 1 || portNumber > 65535)
			{
				co_return;
			}
			streamSocketListener.ConnectionReceived({ this, &ServerPage::OnConnectionReceived });
			co_await streamSocketListener.BindServiceNameAsync(L"1337"/*hstring(std::to_wstring(portNumber))*/);
			serverListBox().Items().Append(box_value(L"server is listening..."));
		}
		catch (hresult_error const& error)
		{

		}
	}

	Windows::Foundation::IAsyncAction ServerPage::StartClient()
	{
		try
		{
			Windows::Networking::HostName hostName{ L"localhost" };
			clientListBox().Items().Append(box_value(L"client is trying to connect..."));
			co_await streamSocket.ConnectAsync(hostName, L"1337");
			clientListBox().Items().Append(box_value(L"client connected"));
			Windows::Storage::Streams::DataWriter dataWriter{ streamSocket.OutputStream() };
			hstring request{ L"Hello, World!" };
			dataWriter.WriteUInt32(request.size());
			dataWriter.WriteString(request);
			co_await dataWriter.StoreAsync();
			std::wstringstream wstringstream;
			wstringstream << L"client sent the request: \"" << request.c_str() << L"\"";
			clientListBox().Items().Append(box_value(wstringstream.str().c_str()));
			co_await dataWriter.FlushAsync();
			dataWriter.DetachStream();
			Windows::Storage::Streams::DataReader dataReader{ streamSocket.InputStream() };
			unsigned int bytesLoaded = co_await dataReader.LoadAsync(sizeof(unsigned int));
			unsigned int stringLength = dataReader.ReadUInt32();
			bytesLoaded = co_await dataReader.LoadAsync(stringLength);
			hstring response{ dataReader.ReadString(bytesLoaded) };
			wstringstream.str(L"");
			wstringstream << L"client received the response: \"" << response.c_str() << L"\"";
			clientListBox().Items().Append(box_value(wstringstream.str().c_str()));
			streamSocket = nullptr;
			clientListBox().Items().Append(box_value(L"client closed its socket"));
		}
		catch (hresult_error const& error)
		{

		}
	}
}
