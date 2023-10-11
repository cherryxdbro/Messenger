#include "pch.h"

#include "MainPage.h"

#include "ClientPage.h"
#include "ServerPage.h"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Messenger::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();
    }

    void MainPage::OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs const& e) const
    {
        __super::OnNavigatedTo(e);
        Frame().IsEnabled(true);
    }

    void MainPage::ClientButton_Click(IInspectable const&, RoutedEventArgs const&) const
    {
        Frame().IsEnabled(false);
        Frame().Navigate(xaml_typename<Messenger::ClientPage>());
    }

    void MainPage::ServerButton_Click(IInspectable const&, RoutedEventArgs const&) const
    {
        Frame().IsEnabled(false);
        Frame().Navigate(xaml_typename<Messenger::ServerPage>());
    }
}
