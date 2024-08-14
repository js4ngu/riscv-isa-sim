// vmod.vv vd, vs1, vs2, vm
/*
VI_VV_LOOP
({
  vd = vs1 % vs2 + vs2_0;
})
*/

VI_CHECK_SSS(true) \
VI_LOOP_BASE \
if (sew == e8) { \
  int8_t UNUSED &vd = P.VU.elt<int8_t>(rd_num, i, true); 
  int8_t vs1 = P.VU.elt<int8_t>(rs1_num, i); 
  int8_t UNUSED vs2 = P.VU.elt<int8_t>(rs2_num, i);
  vd = vs1 % vs2;
  //type_sew_t<e8>::type test_0 = P.VU.elt<type_sew_t<e8>::type>(rs2_num, 0); 
  //vd = vs1 % vs2 + test_0;

} else if (sew == e16) { \
  int16_t UNUSED &vd = P.VU.elt<int16_t>(rd_num, i, true); 
  int16_t vs1 = P.VU.elt<int16_t>(rs1_num, i); 
  int16_t UNUSED vs2 = P.VU.elt<int16_t>(rs2_num, i);
  vd = vs1 % vs2;
  //type_sew_t<e16>::type test_0 = P.VU.elt<type_sew_t<e16>::type>(rs2_num, 0); 
  //vd = vs1 % vs2 + test_0;

} else if (sew == e32) { \
  int32_t UNUSED &vd = P.VU.elt<int32_t>(rd_num, i, true); 
  int32_t vs1 = P.VU.elt<int32_t>(rs1_num, i); 
  int32_t UNUSED vs2 = P.VU.elt<int32_t>(rs2_num, i);
  vd = vs1 % vs2;
  //type_sew_t<e32>::type test_0 = P.VU.elt<type_sew_t<e32>::type>(rs2_num, 0); 
  //vd = vs1 % vs2 + test_0;

} else if (sew == e64) { \
  int64_t UNUSED &vd = P.VU.elt<int64_t>(rd_num, i, true); 
  int64_t vs1 = P.VU.elt<int64_t>(rs1_num, i); 
  int64_t UNUSED vs2 = P.VU.elt<int64_t>(rs2_num, i);
  vd = vs1 % vs2;
  //type_sew_t<e32>::type test_0 = P.VU.elt<type_sew_t<e32>::type>(rs2_num, 0); 
  //vd = vs1 % vs2 + test_0;
  
} \
VI_LOOP_END 

