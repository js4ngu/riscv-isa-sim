// vfrope.vf vd, vs2, rs1

VI_CHECK_SSS(false); \
VI_VFP_COMMON \
for (reg_t i = P.VU.vstart->read(); i < vl; ++i) { \
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
      float32_t &new_token = P.VU.elt<float32_t>(rd_num, i, true); \
      float32_t m = f32(READ_FREG(rs1_num)); \
      float32_t token = P.VU.elt<float32_t>(rs2_num, i);
      uint64_t n_dim = (uint64_t)vl; \
      int is_even = (int)(i % 2 == 0);
      new_token = f32_rope(token, m,  i, n_dim, is_even);
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
