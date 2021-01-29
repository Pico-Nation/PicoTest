#pragma once

#include <picoio/picoio.hpp>

class [[picoio::contract]] test_api_db : public picoio::contract {
public:
   using picoio::contract::contract;

   [[picoio::action("pg")]]
   void primary_i64_general();

   [[picoio::action("pl")]]
   void primary_i64_lowerbound();

   [[picoio::action("pu")]]
   void primary_i64_upperbound();

   [[picoio::action("s1g")]]
   void idx64_general();

   [[picoio::action("s1l")]]
   void idx64_lowerbound();

   [[picoio::action("s1u")]]
   void idx64_upperbound();

   [[picoio::action("tia")]]
   void test_invalid_access( picoio::name code, uint64_t val, uint32_t index, bool store );

   [[picoio::action("sdnancreate")]]
   void idx_double_nan_create_fail();

   [[picoio::action("sdnanmodify")]]
   void idx_double_nan_modify_fail();

   [[picoio::action("sdnanlookup")]]
   void idx_double_nan_lookup_fail( uint32_t lookup_type );

   [[picoio::action("sk32align")]]
   void misaligned_secondary_key256_tests();

};
