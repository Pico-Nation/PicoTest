#pragma once

#include <picoio/picoio.hpp>

class [[picoio::contract]] asserter : public picoio::contract {
public:
   using picoio::contract::contract;

   [[picoio::action]]
   void procassert( int8_t condition, std::string message );

   [[picoio::action]]
   void provereset();
};
