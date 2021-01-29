#pragma once
#include <fc/variant.hpp>
#include <picoio/trace_api/trace.hpp>
#include <picoio/chain/abi_def.hpp>
#include <picoio/chain/protocol_feature_activation.hpp>

namespace picoio { namespace trace_api {

   using data_log_entry = fc::static_variant<
      block_trace_v0,
      block_trace_v1
   >;

}}
