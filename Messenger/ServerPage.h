#pragma once

#include "ServerPage.g.h"

#include "NetworkActionViewModel.h"

namespace winrt::Messenger::implementation
{
    struct ServerPage : ServerPageT<ServerPage>
    {
        ServerPage();

        void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs const& e) const;

        void BackButton_Click(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& e) const;
        void ServerMenuButton_Click(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& e);
        void StartServerButton_Click(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& e);
        void AddVLANButton_Click(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& e);

        Messenger::NetworkActionViewModel ClientNetworkActionViewModel();
        Messenger::NetworkActionViewModel ServerNetworkActionViewModel();

    private:

        Windows::Foundation::IAsyncAction OnConnectionReceived(Windows::Networking::Sockets::StreamSocketListener const& sender, Windows::Networking::Sockets::StreamSocketListenerConnectionReceivedEventArgs const& args);
        Windows::Foundation::IAsyncAction StartServer();
        Windows::Foundation::IAsyncAction StartClient();

        static Windows::Networking::Sockets::StreamSocketListener streamSocketListener;
        static Windows::Networking::Sockets::StreamSocket streamSocket;

        Messenger::NetworkActionViewModel m_clientNetworkActionViewModel;
        Messenger::NetworkActionViewModel m_serverNetworkActionViewModel;
    };
}

namespace winrt::Messenger::factory_implementation
{
    struct ServerPage : ServerPageT<ServerPage, implementation::ServerPage>
    {

    };
}
