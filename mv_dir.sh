
#TEMP_DIR=`echo "$INPUT_FILE" | sed -e "s:/:_:g"`
#for ((i=0 ; i<100 ; i++))
cd Output
for _3FIGURE in `seq -f %03g 1 207`
do
  #a=$(($i+7209920 ))
  dir="_gpfs_fs2001_yfukuhar_data_user.yfukuhar.mc16_13TeV.361107.PowhegPythia8EvtGen_AZNLOCTEQ6L1_Zmumu.recon.RDO.e3601_s3126_r9781.201806291853_EXT0_user.yfukuhar.14514992.EXT0._000"${_3FIGURE}".RDO.pool.root/"
  mv $dir "DIR_yfukuhar_Zmumu_AOD"${_3FIGURE}

done
#_gpfs_fs2001_yfukuhar_data_user.yfukuhar.mc16_13TeV.361107.PowhegPythia8EvtGen_AZNLOCTEQ6L1_Zmumu.recon.RDO.e3601_s3126_r9781.201806291853_EXT0_user.yfukuhar.14514992.EXT0._000207.RDO.pool.root/
#_gpfs_fs2001_yfukuhar_data_user.yfukuhar.mc16_13TeV.361107.PowhegPythia8EvtGen_AZNLOCTEQ6L1_Zmumu.recon.RDO.e3601_s3126_r9781.201806291853_EXT0_user.yfukuhar.14514992.EXT0._000002.RDO.pool.root
