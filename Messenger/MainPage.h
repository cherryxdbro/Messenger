#pragma once

#include "MainPage.g.h"

namespace winrt::Messenger::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();

        void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs const& e) const;

        void ClientButton_Click(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args) const;
        void ServerButton_Click(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args) const;
    };
}

namespace winrt::Messenger::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {

    };
}
