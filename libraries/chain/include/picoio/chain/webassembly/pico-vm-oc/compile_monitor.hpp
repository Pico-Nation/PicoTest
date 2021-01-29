#pragma once

#include <picoio/chain/webassembly/pico-vm-oc/config.hpp>

#include <boost/asio/local/datagram_protocol.hpp>
#include <picoio/chain/webassembly/pico-vm-oc/ipc_helpers.hpp>

namespace picoio { namespace chain { namespace picovmoc {

wrapped_fd get_connection_to_compile_monitor(int cache_fd);

}}}