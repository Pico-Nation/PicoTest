#pragma once

#include <picoio/picoio.hpp>

class [[picoio::contract]] ram_restrictions_test : public picoio::contract {
public:
   struct [[picoio::table]] data {
      uint64_t           key;
      std::vector<char>  value;

      uint64_t primary_key() const { return key; }
   };

   typedef picoio::multi_index<"tablea"_n, data> tablea;
   typedef picoio::multi_index<"tableb"_n, data> tableb;

public:
   using picoio::contract::contract;

   [[picoio::action]]
   void noop();

   [[picoio::action]]
   void setdata( uint32_t len1, uint32_t len2, picoio::name payer );

   [[picoio::action]]
   void notifysetdat( picoio::name acctonotify, uint32_t len1, uint32_t len2, picoio::name payer );

   [[picoio::on_notify("tester2::notifysetdat")]]
   void on_notify_setdata( picoio::name acctonotify, uint32_t len1, uint32_t len2, picoio::name payer );

   [[picoio::action]]
   void senddefer( uint64_t senderid, picoio::name payer );

   [[picoio::action]]
   void notifydefer( picoio::name acctonotify, uint64_t senderid, picoio::name payer );

   [[picoio::on_notify("tester2::notifydefer")]]
   void on_notifydefer( picoio::name acctonotify, uint64_t senderid, picoio::name payer );

};
