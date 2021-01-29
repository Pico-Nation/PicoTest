#include <picoio/chain/webassembly/pico-vm-oc.hpp>
#include <picoio/chain/wasm_picoio_constraints.hpp>
#include <picoio/chain/wasm_picoio_injection.hpp>
#include <picoio/chain/apply_context.hpp>
#include <picoio/chain/exceptions.hpp>

#include <vector>
#include <iterator>

namespace picoio { namespace chain { namespace webassembly { namespace picovmoc {

class picovmoc_instantiated_module : public wasm_instantiated_module_interface {
   public:
      picovmoc_instantiated_module(const digest_type& code_hash, const uint8_t& vm_version, picovmoc_runtime& wr) :
         _code_hash(code_hash),
         _vm_version(vm_version),
         _picovmoc_runtime(wr)
      {

      }

      ~picovmoc_instantiated_module() {
         _picovmoc_runtime.cc.free_code(_code_hash, _vm_version);
      }

      void apply(apply_context& context) override {
         const code_descriptor* const cd = _picovmoc_runtime.cc.get_descriptor_for_code_sync(_code_hash, _vm_version);
         PICO_ASSERT(cd, wasm_execution_error, "PICO VM OC instantiation failed");

         _picovmoc_runtime.exec.execute(*cd, _picovmoc_runtime.mem, context);
      }

      const digest_type              _code_hash;
      const uint8_t                  _vm_version;
      picovmoc_runtime&               _picovmoc_runtime;
};

picovmoc_runtime::picovmoc_runtime(const boost::filesystem::path data_dir, const picovmoc::config& picovmoc_config, const chainbase::database& db)
   : cc(data_dir, picovmoc_config, db), exec(cc) {
}

picovmoc_runtime::~picovmoc_runtime() {
}

std::unique_ptr<wasm_instantiated_module_interface> picovmoc_runtime::instantiate_module(const char* code_bytes, size_t code_size, std::vector<uint8_t> initial_memory,
                                                                                     const digest_type& code_hash, const uint8_t& vm_type, const uint8_t& vm_version) {

   return std::make_unique<picovmoc_instantiated_module>(code_hash, vm_type, *this);
}

//never called. PICO VM OC overrides picoio_exit to its own implementation
void picovmoc_runtime::immediately_exit_currently_running_module() {}

}}}}
