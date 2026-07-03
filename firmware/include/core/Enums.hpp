#pragma once

enum class ObservationType
{
    Temperature,
    Voltage,
    Current,
    Pressure,
    Humidity,
    Acceleration,
    Gyroscope,
    State,
    Custom
};

enum class DataQuality
{
    Good,
    Suspect,
    Invalid
};

enum class EventSeverity
{
    Info,
    Warning,
    Error,
    Critical
};