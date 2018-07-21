#DIR="/gpfs/fs2001/yfukuhar/data/Data_default_AOD/*"
#LISTNAME="./Data_default_AOD.list"

#DIR="/gpfs/fs2001/yfukuhar/data/Data_noRpcHit_AOD/*"
#LISTNAME="/gpfs/home/yfukuhar/work/CalcEffTool/run/list/Data_noRpcHit_AOD.list"

#DIR="/gpfs/fs2001/yfukuhar/data/user.yfukuhar.mc16_13TeV.361107.PowhegPythia8EvtGen_AZNLOCTEQ6L1_Zmumu.recon.RDO.e3601_s3126_r9781.201806291853_EXT0/*"
#LISTNAME="/gpfs/fs2001/yfukuhar/workspace/AthenaAnalysis/noRpcHit_21_0/AthenaForEachBranch/default/LocalAthena/run/zmumu.list"

#DIR="/gpfs/fs2001/yfukuhar/data/youhei_Zmumu_AOD/Zmumu_default/DIR_default_user.yfukuhar.14514992.EXT0*/AOD.pool.root"
#LISTNAME="/gpfs/home/yfukuhar/work/CalcEffTool/run/list/youhei_Zmumu_AOD_default.list"

#DIR="/gpfs/fs2001/yfukuhar/data/youhei_Zmumu_AOD/Zmumu_noRpcHit/DIR_noRpcHit_user.yfukuhar.14514992.*/AOD.pool.root"
#LISTNAME="/gpfs/home/yfukuhar/work/CalcEffTool/run/list/youhei_Zmumu_AOD_noRpcHit.list"

#DIR="/gpfs/fs2001/yfukuhar/data/youhei_Zmumu_AOD/Zmumu_noRpcHitWide/DIR_noRpcHitWide_user.yfukuhar.14514992.*/AOD.pool.root"
#LISTNAME="/gpfs/home/yfukuhar/work/CalcEffTool/run/list/youhei_Zmumu_AOD_noRpcHitWide.list"

#DIR="/gpfs/fs2001/yfukuhar/workspace/AthenaAnalysis/noRpcHit_21_0/AthenaForEachBranch/noRpcHitWide/LocalAthena/run/Output/DIR_yfukuhar_Zmumu_AOD*/user.yfukuhar.mc16_13TeV.Zmumu.AOD.201807180800.root"
#LISTNAME="/gpfs/home/yfukuhar/work/CalcEffTool/run/list/yfukuhara_Zmumu_AOD_noRpcHitWide.list"

#DIR="/gpfs/fs2001/yfukuhar/workspace/AthenaAnalysis/noRpcHit_21_0/AthenaForEachBranch/noRpcHitWide1/LocalAthena/run/Output/DIR_yfukuhar_Zmumu_AOD*/user.yfukuhar.mc16_13TeV.Zmumu.AOD.201807181425.root"
#LISTNAME="/gpfs/home/yfukuhar/work/CalcEffTool/run/list/yfukuhara_Zmumu_AOD_noRpcHitWide1.list"

#JDIR="/gpfs/fs2001/yfukuhar/workspace/AthenaAnalysis/noRpcHit_21_0/AthenaForEachBranch/noRpcHitWide2/LocalAthena/run/Output/DIR_yfukuhar_Zmumu_AOD*/user.yfukuhar.mc16_13TeV.Zmumu.AOD.201807181619.root"
#JLISTNAME="/gpfs/home/yfukuhar/work/CalcEffTool/run/list/yfukuhara_Zmumu_AOD_noRpcHitWide2.list"

#DIR="/gpfs/fs2001/yfukuhar/data/youhei_Zmumu_AOD/Zmumu_MdtRegion/Zmumu_MdtRegion/*/AOD.pool.root"
#LISTNAME="/gpfs/home/yfukuhar/work/CalcEffTool/run/list/youhei_Zmumu_AOD_MdtRegion.list"

DIR="/gpfs/fs6001/yfukuhar/workspace/AthenaAnalysis/noRpcHit_21_0/AthenaForEachBranch/noRpcHitCommentOut/LocalAthena/run/Output/DIR_yfukuhar_Zmumu_AOD*/user.yfukuhar*.root"
LISTNAME="/gpfs/home/yfukuhar/work/CalcEffTool/run/list/yfukuhara_Zmumu_AOD_noRpcHitCommentOut.list"


if [ -e $LISTNAME ]; then
  rm -i $LISTNAME
fi

for filepath in ${DIR}; do
  echo $filepath | tee -a ${LISTNAME}
done

echo "DIR: "$DIR
echo "LISTNAME: "$LISTNAME
