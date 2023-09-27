#include "pch.h"

#include "MainPage.xaml.h"
#include "ServerPage.xaml.h"

#if __has_include("MainPage.g.cpp")
#include "MainPage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

namespace winrt::Messenger::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();
    }

    void MainPage::ClientButton_Click(IInspectable const&, RoutedEventArgs const&)
    {

    }

    void MainPage::ServerButton_Click(IInspectable const&, RoutedEventArgs const&)
    {

    }
}
