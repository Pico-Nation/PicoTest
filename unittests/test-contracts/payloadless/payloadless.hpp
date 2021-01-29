#pragma once

#include <picoio/picoio.hpp>

class [[picoio::contract]] payloadless : public picoio::contract {
public:
   using picoio::contract::contract;

   [[picoio::action]]
   void doit();
};
