#include "pch.h"

#include "ClientPage.h"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Messenger::implementation
{
	ClientPage::ClientPage()
	{

	}

	void ClientPage::OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs const& e) const
	{
		__super::OnNavigatedTo(e);
		Frame().IsEnabled(true);
	}

	void ClientPage::BackButton_Click(IInspectable const&, RoutedEventArgs const&) const
	{
		Frame().IsEnabled(false);
		Frame().GoBack();
	}

	void ClientPage::ClientButton_Click(IInspectable const&, RoutedEventArgs const&)
	{

	}

	void ClientPage::ServerButton_Click(IInspectable const&, RoutedEventArgs const&)
	{

	}
}
