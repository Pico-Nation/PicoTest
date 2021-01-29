#pragma once

#include <picoio/picoio.hpp>
#include <picoio/singleton.hpp>
#include <picoio/asset.hpp>

// Extacted from picoio.token contract:
namespace picoio {
   class [[picoio::contract("picoio.token")]] token : public picoio::contract {
   public:
      using picoio::contract::contract;

      [[picoio::action]]
      void transfer( picoio::name        from,
                     picoio::name        to,
                     picoio::asset       quantity,
                     const std::string& memo );
      using transfer_action = picoio::action_wrapper<"transfer"_n, &token::transfer>;
   };
}

// This contract:
class [[picoio::contract]] proxy : public picoio::contract {
public:
   proxy( picoio::name self, picoio::name first_receiver, picoio::datastream<const char*> ds );

   [[picoio::action]]
   void setowner( picoio::name owner, uint32_t delay );

   [[picoio::on_notify("picoio.token::transfer")]]
   void on_transfer( picoio::name        from,
                     picoio::name        to,
                     picoio::asset       quantity,
                     const std::string& memo );

   [[picoio::on_notify("picoio::onerror")]]
   void on_error( uint128_t sender_id, picoio::ignore<std::vector<char>> sent_trx );

   struct [[picoio::table]] config {
      picoio::name owner;
      uint32_t    delay   = 0;
      uint32_t    next_id = 0;

      PICOLIB_SERIALIZE( config, (owner)(delay)(next_id) )
   };

   using config_singleton = picoio::singleton< "config"_n,  config >;

protected:
   config_singleton _config;
};
