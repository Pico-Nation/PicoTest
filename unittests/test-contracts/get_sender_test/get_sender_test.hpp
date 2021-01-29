#pragma once

#include <picoio/picoio.hpp>

namespace picoio {
   namespace internal_use_do_not_use {
      extern "C" {
         __attribute__((picoio_wasm_import))
         uint64_t get_sender();
      }
   }
}

namespace picoio {
   name get_sender() {
      return name( internal_use_do_not_use::get_sender() );
   }
}

class [[picoio::contract]] get_sender_test : public picoio::contract {
public:
   using picoio::contract::contract;

   [[picoio::action]]
   void assertsender( picoio::name expected_sender );
   using assertsender_action = picoio::action_wrapper<"assertsender"_n, &get_sender_test::assertsender>;

   [[picoio::action]]
   void sendinline( picoio::name to, picoio::name expected_sender );

   [[picoio::action]]
   void notify( picoio::name to, picoio::name expected_sender, bool send_inline );

   [[picoio::on_notify("*::notify")]]
   void on_notify( picoio::name to, picoio::name expected_sender, bool send_inline );

};
