#pragma once

#include "ClientPage.g.h"

namespace winrt::Messenger::implementation
{
    struct ClientPage : ClientPageT<ClientPage>
    {
        ClientPage();

        void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs const& e) const;

        void BackButton_Click(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& e) const;
        void ClientButton_Click(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& e);
        void ServerButton_Click(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::Messenger::factory_implementation
{
    struct ClientPage : ClientPageT<ClientPage, implementation::ClientPage>
    {

    };
}
