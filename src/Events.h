#pragma once
#include <eventpp/hetereventdispatcher.h>

// A central place for all application-wide event types
enum class Event {
    KeyPressed,
    BackspacePressed,
};

using EventDispatcher = eventpp::HeterEventDispatcher<Event, void(char), void>;
inline EventDispatcher eventDispatcher;