#include "pch.h"

#include "ServerPage.xaml.h"
#if __has_include("ServerPage.g.cpp")
#include "ServerPage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

namespace winrt::Messenger::implementation
{
    ServerPage::ServerPage()
    {
        InitializeComponent();
    }

    void ServerPage::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
    }

    void ServerPage::myButton2_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        myButton2().Content(box_value(L"Clicked"));
    }
}
