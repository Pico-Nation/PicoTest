#pragma once

#include <picoio/picoio.hpp>
#include <vector>

class [[picoio::contract]] deferred_test : public picoio::contract {
public:
   using picoio::contract::contract;

   [[picoio::action]]
   void defercall( picoio::name payer, uint64_t sender_id, picoio::name contract, uint64_t payload );

   [[picoio::action]]
   void delayedcall( picoio::name payer, uint64_t sender_id, picoio::name contract,
                     uint64_t payload, uint32_t delay_sec, bool replace_existing );

   [[picoio::action]]
   void deferfunc( uint64_t payload );
   using deferfunc_action = picoio::action_wrapper<"deferfunc"_n, &deferred_test::deferfunc>;

   [[picoio::action]]
   void inlinecall( picoio::name contract, picoio::name authorizer, uint64_t payload );

   [[picoio::action]]
   void fail();

   [[picoio::on_notify("picoio::onerror")]]
   void on_error( uint128_t sender_id, picoio::ignore<std::vector<char>> sent_trx );
};
