#include "pch.h"

#include "NetworkAction.h"

namespace winrt::Messenger::implementation
{
    NetworkAction::NetworkAction(hstring const& title) : m_title(title)
    {

    }

    hstring NetworkAction::Title()
    {
        return m_title;
    }

    void NetworkAction::Title(hstring const& value)
    {
        if (m_title != value)
        {
            m_title = value;
            m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Title" });
        }
    }

    event_token NetworkAction::PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }

    void NetworkAction::PropertyChanged(event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
}
