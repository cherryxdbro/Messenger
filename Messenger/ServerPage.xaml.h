#pragma once

#include "ServerPage.g.h"

namespace winrt::Messenger::implementation
{
    struct ServerPage : ServerPageT<ServerPage>
    {
        ServerPage();

        void myButton_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void myButton2_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::Messenger::factory_implementation
{
    struct ServerPage : ServerPageT<ServerPage, implementation::ServerPage>
    {

    };
}
