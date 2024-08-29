// vfrope.vf vd, vs2, rs1
VI_CHECK_SSS(false); \
VI_VFP_COMMON \

uint64_t base_index = READ_REG(30);\
uint64_t m          = READ_REG(31);\

for (reg_t i = P.VU.vstart->read(); i < vl; i = i + 2) { \
  VI_LOOP_ELEMENT_SKIP();
  switch (P.VU.vsew) { \
    case e16: { \
      float16_t &new_token = P.VU.elt<float16_t>(rd_num, i, true); \
      float16_t m = f16(READ_FREG(rs1_num)); \
      float16_t token = P.VU.elt<float16_t>(rs2_num, i);
      uint64_t n_dim = (uint64_t)vl; \
      int is_even = (int)(i % 2 == 0);
      new_token = f16_rope(token, m,  i, n_dim, is_even); \
      set_fp_exceptions; \
      break; \
    } \

    case e32: { \
      float32_t x_1 = P.VU.elt<float32_t>(rs2_num, i);
      float32_t x_2 = P.VU.elt<float32_t>(rs2_num, i+1);

      float32_t &y_1 = P.VU.elt<float32_t>(rd_num, i, true); \
      float32_t &y_2 = P.VU.elt<float32_t>(rd_num, i+1, true); \

      float32_t theta = f32(READ_FREG(rs1_num)); \
      f32_rope(x_1, x_2, &y_1, &y_2, theta, m, i, base_index);\
      set_fp_exceptions; \
      break; \
    } \

    case e64: { \
      float64_t &new_token = P.VU.elt<float64_t>(rd_num, i, true); \
      float64_t m = f64(READ_FREG(rs1_num)); \
      float64_t token = P.VU.elt<float64_t>(rs2_num, i);
      uint64_t n_dim = (uint64_t)vl; \
      int is_even = (int)(i % 2 == 0);
      new_token = f64_rope(token, m,  i, n_dim, is_even); \
      set_fp_exceptions; \
      break; \
    } \
    default: \
      require(0); \
      break; \
  }; \
  DEBUG_RVV_FP_VF; \
VI_VFP_LOOP_END