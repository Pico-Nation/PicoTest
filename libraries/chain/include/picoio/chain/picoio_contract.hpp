#pragma once

#include <picoio/chain/types.hpp>
#include <picoio/chain/contract_types.hpp>

namespace picoio { namespace chain {

   class apply_context;

   /**
    * @defgroup native_action_handlers Native Action Handlers
    */
   ///@{
   void apply_picoio_newaccount(apply_context&);
   void apply_picoio_updateauth(apply_context&);
   void apply_picoio_deleteauth(apply_context&);
   void apply_picoio_linkauth(apply_context&);
   void apply_picoio_unlinkauth(apply_context&);

   /*
   void apply_picoio_postrecovery(apply_context&);
   void apply_picoio_passrecovery(apply_context&);
   void apply_picoio_vetorecovery(apply_context&);
   */

   void apply_picoio_setcode(apply_context&);
   void apply_picoio_setabi(apply_context&);

   void apply_picoio_canceldelay(apply_context&);
   ///@}  end action handlers

} } /// namespace picoio::chain
