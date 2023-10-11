#pragma once

#include "NetworkAction.g.h"

namespace winrt::Messenger::implementation
{
    struct NetworkAction : NetworkActionT<NetworkAction>
    {
        NetworkAction() = delete;
        NetworkAction(hstring const& title);

        hstring Title();
        void Title(hstring const& value);
        event_token PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(event_token const& token) noexcept;

    private:
        hstring m_title;
        event<Windows::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
    };
}

namespace winrt::Messenger::factory_implementation
{
    struct NetworkAction : NetworkActionT<NetworkAction, implementation::NetworkAction>
    {

    };
}
