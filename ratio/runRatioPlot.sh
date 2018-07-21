
#void tmp_ratio_mu4(TString name_file_bunshi, TString name_file_bunbo, TString name_hist_bunshi, TString name_hist_bunbo, TString name_pdf){

#FILE_BUNSHI="/gpfs/home/yfukuhar/work/RpcL2MuonSA/RpcL2MuonSA/src/outroot/youhei_Zmumu_AOD_MdtRegion.root"
FILE_BUNSHI="/gpfs/home/yfukuhar/work/RpcL2MuonSA/RpcL2MuonSA/src/outroot/youhei_Zmumu_AOD_noRpcHit.root"
FILE_BUNBO="/gpfs/home/yfukuhar/work/RpcL2MuonSA/RpcL2MuonSA/src/outroot/youhei_Zmumu_AOD_MdtRegion.root"
HIST_BUNSHI="h_eff_eta_mu50_L1SA"
HIST_BUNBO="h_eff_eta_mu50_L1SA"
PDF="./test_ratioPlot.pdf"
#LEGEND_BUNSHI="noRpcHit"
LEGEND_BUNSHI="MdtRegion"
LEGEND_BUNBO="default"

root -b -l -q "ratioPlot.cxx++(\"${FILE_BUNSHI}\", \"${FILE_BUNBO}\", \"${HIST_BUNSHI}\", \"${HIST_BUNBO}\", \"${PDF}\", \"${LEGEND_BUNSHI}\", \"${LEGEND_BUNBO}\")"

#root -l -b "PDFMaker_JPsi.C++(\"$INPUT_ROOT_FILE\",\"$OUTPUT_PDF_FILE\",\"$JPSIZ\",\"$KIND\",\"$DIM\",\"$V    ARIABLE\",\"$TRIGGER\",\"$CHAIN\")"
