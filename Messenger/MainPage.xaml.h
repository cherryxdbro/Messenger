#pragma once

#include "MainPage.g.h"

namespace winrt::Messenger::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();

        void ClientButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void ServerButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::Messenger::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {

    };
}
