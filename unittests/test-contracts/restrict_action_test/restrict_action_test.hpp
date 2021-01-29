#pragma once

#include <picoio/picoio.hpp>

class [[picoio::contract]] restrict_action_test : public picoio::contract {
public:
   using picoio::contract::contract;

   [[picoio::action]]
   void noop( );

   [[picoio::action]]
   void sendinline( picoio::name authorizer );

   [[picoio::action]]
   void senddefer( picoio::name authorizer, uint32_t senderid );


   [[picoio::action]]
   void notifyinline( picoio::name acctonotify, picoio::name authorizer );

   [[picoio::action]]
   void notifydefer( picoio::name acctonotify, picoio::name authorizer, uint32_t senderid );

   [[picoio::on_notify("testacc::notifyinline")]]
   void on_notify_inline( picoio::name acctonotify, picoio::name authorizer );

   [[picoio::on_notify("testacc::notifydefer")]]
   void on_notify_defer( picoio::name acctonotify, picoio::name authorizer, uint32_t senderid );
};
