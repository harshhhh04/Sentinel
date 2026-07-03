#pragma once

#include "core/Types.hpp"
#include "core/Enums.hpp"

struct Observation
{
    ObservationID observation_id;

    Timestamp timestamp;

    SourceID source_id;

    ObservationType type;

    DataQuality quality;

    Value value;
};