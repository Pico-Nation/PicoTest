#include <picoiolib/picoio.hpp>

#include "test_api.hpp"

void test_types::types_size() {

   picoio_assert( sizeof(int64_t)   ==  8, "int64_t size != 8"   );
   picoio_assert( sizeof(uint64_t)  ==  8, "uint64_t size != 8"  );
   picoio_assert( sizeof(uint32_t)  ==  4, "uint32_t size != 4"  );
   picoio_assert( sizeof(int32_t)   ==  4, "int32_t size != 4"   );
   picoio_assert( sizeof(uint128_t) == 16, "uint128_t size != 16");
   picoio_assert( sizeof(int128_t)  == 16, "int128_t size != 16" );
   picoio_assert( sizeof(uint8_t)   ==  1, "uint8_t size != 1"   );

   picoio_assert( sizeof(picoio::name) ==  8, "name size !=  8");
}

void test_types::char_to_symbol() {

   picoio_assert( picoio::name::char_to_value('1') ==  1, "picoio::char_to_symbol('1') !=  1" );
   picoio_assert( picoio::name::char_to_value('2') ==  2, "picoio::char_to_symbol('2') !=  2" );
   picoio_assert( picoio::name::char_to_value('3') ==  3, "picoio::char_to_symbol('3') !=  3" );
   picoio_assert( picoio::name::char_to_value('4') ==  4, "picoio::char_to_symbol('4') !=  4" );
   picoio_assert( picoio::name::char_to_value('5') ==  5, "picoio::char_to_symbol('5') !=  5" );
   picoio_assert( picoio::name::char_to_value('a') ==  6, "picoio::char_to_symbol('a') !=  6" );
   picoio_assert( picoio::name::char_to_value('b') ==  7, "picoio::char_to_symbol('b') !=  7" );
   picoio_assert( picoio::name::char_to_value('c') ==  8, "picoio::char_to_symbol('c') !=  8" );
   picoio_assert( picoio::name::char_to_value('d') ==  9, "picoio::char_to_symbol('d') !=  9" );
   picoio_assert( picoio::name::char_to_value('e') == 10, "picoio::char_to_symbol('e') != 10" );
   picoio_assert( picoio::name::char_to_value('f') == 11, "picoio::char_to_symbol('f') != 11" );
   picoio_assert( picoio::name::char_to_value('g') == 12, "picoio::char_to_symbol('g') != 12" );
   picoio_assert( picoio::name::char_to_value('h') == 13, "picoio::char_to_symbol('h') != 13" );
   picoio_assert( picoio::name::char_to_value('i') == 14, "picoio::char_to_symbol('i') != 14" );
   picoio_assert( picoio::name::char_to_value('j') == 15, "picoio::char_to_symbol('j') != 15" );
   picoio_assert( picoio::name::char_to_value('k') == 16, "picoio::char_to_symbol('k') != 16" );
   picoio_assert( picoio::name::char_to_value('l') == 17, "picoio::char_to_symbol('l') != 17" );
   picoio_assert( picoio::name::char_to_value('m') == 18, "picoio::char_to_symbol('m') != 18" );
   picoio_assert( picoio::name::char_to_value('n') == 19, "picoio::char_to_symbol('n') != 19" );
   picoio_assert( picoio::name::char_to_value('o') == 20, "picoio::char_to_symbol('o') != 20" );
   picoio_assert( picoio::name::char_to_value('p') == 21, "picoio::char_to_symbol('p') != 21" );
   picoio_assert( picoio::name::char_to_value('q') == 22, "picoio::char_to_symbol('q') != 22" );
   picoio_assert( picoio::name::char_to_value('r') == 23, "picoio::char_to_symbol('r') != 23" );
   picoio_assert( picoio::name::char_to_value('s') == 24, "picoio::char_to_symbol('s') != 24" );
   picoio_assert( picoio::name::char_to_value('t') == 25, "picoio::char_to_symbol('t') != 25" );
   picoio_assert( picoio::name::char_to_value('u') == 26, "picoio::char_to_symbol('u') != 26" );
   picoio_assert( picoio::name::char_to_value('v') == 27, "picoio::char_to_symbol('v') != 27" );
   picoio_assert( picoio::name::char_to_value('w') == 28, "picoio::char_to_symbol('w') != 28" );
   picoio_assert( picoio::name::char_to_value('x') == 29, "picoio::char_to_symbol('x') != 29" );
   picoio_assert( picoio::name::char_to_value('y') == 30, "picoio::char_to_symbol('y') != 30" );
   picoio_assert( picoio::name::char_to_value('z') == 31, "picoio::char_to_symbol('z') != 31" );

   for(unsigned char i = 0; i<255; i++) {
      if( (i >= 'a' && i <= 'z') || (i >= '1' || i <= '5') ) continue;
      picoio_assert( picoio::name::char_to_value((char)i) == 0, "picoio::char_to_symbol() != 0" );
   }
}

void test_types::string_to_name() {
   return;
   picoio_assert( picoio::name("a") == "a"_n, "picoio::string_to_name(a)" );
   picoio_assert( picoio::name("ba") == "ba"_n, "picoio::string_to_name(ba)" );
   picoio_assert( picoio::name("cba") == "cba"_n, "picoio::string_to_name(cba)" );
   picoio_assert( picoio::name("dcba") == "dcba"_n, "picoio::string_to_name(dcba)" );
   picoio_assert( picoio::name("edcba") == "edcba"_n, "picoio::string_to_name(edcba)" );
   picoio_assert( picoio::name("fedcba") == "fedcba"_n, "picoio::string_to_name(fedcba)" );
   picoio_assert( picoio::name("gfedcba") == "gfedcba"_n, "picoio::string_to_name(gfedcba)" );
   picoio_assert( picoio::name("hgfedcba") == "hgfedcba"_n, "picoio::string_to_name(hgfedcba)" );
   picoio_assert( picoio::name("ihgfedcba") == "ihgfedcba"_n, "picoio::string_to_name(ihgfedcba)" );
   picoio_assert( picoio::name("jihgfedcba") == "jihgfedcba"_n, "picoio::string_to_name(jihgfedcba)" );
   picoio_assert( picoio::name("kjihgfedcba") == "kjihgfedcba"_n, "picoio::string_to_name(kjihgfedcba)" );
   picoio_assert( picoio::name("lkjihgfedcba") == "lkjihgfedcba"_n, "picoio::string_to_name(lkjihgfedcba)" );
   picoio_assert( picoio::name("mlkjihgfedcba") == "mlkjihgfedcba"_n, "picoio::string_to_name(mlkjihgfedcba)" );
}
