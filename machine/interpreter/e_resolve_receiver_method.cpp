#include "instructions/e_resolve_receiver_method.hpp"

namespace rubinius {
  namespace interpreter {
    intptr_t e_resolve_receiver_method(STATE, CallFrame* call_frame, intptr_t const opcodes[]) {
      instructions::e_resolve_receiver_method(call_frame, argument(0), argument(1));

      call_frame->next_ip(instructions::data_e_resolve_receiver_method.width);

      return ((instructions::Instruction)opcodes[call_frame->ip()])(state, call_frame, opcodes);
    }
  }
}
