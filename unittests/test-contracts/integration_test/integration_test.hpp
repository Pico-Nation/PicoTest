#pragma once

#include <picoio/picoio.hpp>

class [[picoio::contract]] integration_test : public picoio::contract {
public:
   using picoio::contract::contract;

   [[picoio::action]]
   void store( picoio::name from, picoio::name to, uint64_t num );

   struct [[picoio::table("payloads")]] payload {
      uint64_t              key;
      std::vector<uint64_t> data;

      uint64_t primary_key()const { return key; }

      PICOLIB_SERIALIZE( payload, (key)(data) )
   };

   using payloads_table = picoio::multi_index< "payloads"_n,  payload >;

};
