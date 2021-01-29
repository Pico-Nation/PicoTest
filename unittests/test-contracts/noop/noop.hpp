#pragma once

#include <picoio/picoio.hpp>

class [[picoio::contract]] noop : public picoio::contract {
public:
   using picoio::contract::contract;

   [[picoio::action]]
   void anyaction( picoio::name                       from,
                   const picoio::ignore<std::string>& type,
                   const picoio::ignore<std::string>& data );
};
