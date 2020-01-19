#include <TFile.h>
#include <TH1.h>
#include <TCanvas.h>
#include <TString.h>
using namespace std;


void DrawSame(){
  TFile *file1 = new TFile("/gpfs/fs2001/yfukuhar/data/data18_rate/user.yfukuhar.00359918.physics_Main.YFTAP.f969_m2020_RateJPZtapv7_EXT0/merged.root");
  //TFile *file1 = new TFile("/gpfs/home/yfukuhar/work/TestCalcEffTool/CalcEffTool/run/Output/_gpfs_fs6001_yfukuhar_data_data18_rate_data18_13TeV_data18_13TeV.00359918.physics_Main.merge.AOD.f969_m2020._lb0530._0003.1/test0605_01.root");
  //TFile *file1 = new TFile("/gpfs/fs2001/yfukuhar/data/data18_rate/merged.root");
  //TFile *file1 = new TFile("/gpfs/fs2001/yfukuhar/data/data18_rate/user.yfukuhar.00358615.physics_Main.YFTAP.f961_m2020_RateJPZtapv6_EXT0/merged.root");
  //TFile *file1 = new TFile("/gpfs/fs2001/yfukuhar/data/data18_rate/user.yfukuhar.00358577.physics_Main.YFTAP.f961_m2015_RateJPZtapv6_EXT0/merged.root");
  //TFile *file1 = new TFile("/gpfs/fs2001/yfukuhar/data/data18_rate/user.yfukuhar.00358541.physics_Main.YFTAP.f961_m2015_RateJPZtapv6_EXT0/merged.root");
  //TFile *file1 = new TFile("/gpfs/fs2001/yfukuhar/data/data18_rate/user.yfukuhar.00359918.physics_Main.YFTAP.f969_m2020_RateJPZtapv6_EXT0/merged.root");
  TString labelPDF = "merged.pdf";
  TCanvas *c1 = new TCanvas("c1", "c1", 10, 10, 1020, 700);
  c1->SetGrid();
  c1->SetRightMargin(0.20);
  c1->SetLeftMargin(0.23);
  c1->SetBottomMargin(0.20);

  //gStyle->SetPadTopMargin(0.06);
  gStyle->SetLegendBorderSize(0);

  c1 -> Print(labelPDF + "[", "pdf");
  c1 -> Print(labelPDF, "pdf");

  const int nMax = 6;
  Color_t histColor[nMax]        = {10, kYellow-3, kBlue-7, kBlue, kRed-4, kWhite};
  bool isFirstEvent = true;
  TString eachTrig[nMax] = {"L1", "CB", "SA", "Off", "OffPtCut", "Event"};

  typedef std::pair<TString, TString> pair;
  std::vector< pair > trigChain;
  trigChain.push_back( pair("HLT_noalg_L1MU4", "HLT_mu4") );
  trigChain.push_back( pair("HLT_mu4", "HLT_mu4") );
  trigChain.push_back( pair("HLT_noalg_L1MU6", "HLT_mu6") );
  trigChain.push_back( pair("HLT_noalg_L1MU20", "HLT_mu26_ivarmedium") );
  trigChain.push_back( pair("HLT_mu50", "HLT_mu50") );
  trigChain.push_back( pair("HLT_noalg_L1MU20", "HLT_mu50") );
  //trigChain.push_back( pair("HLT_noalg_L1MU4", "HLT_noalg_L1MU4") );

  typedef std::pair<TString, Int_t> pair_trigInfo;
  std::vector< pair_trigInfo > trigInfo;
  trigInfo.push_back( pair_trigInfo("L1MU4", 4) );
  trigInfo.push_back( pair_trigInfo("L1MU4", 4) );
  trigInfo.push_back( pair_trigInfo("L1MU6", 6) );
  trigInfo.push_back( pair_trigInfo("L1MU20", 26) );
  trigInfo.push_back( pair_trigInfo("L1MU20", 50) );
  trigInfo.push_back( pair_trigInfo("L1MU20", 50) );

  // chain loop
  int loop_count = -1;
  for ( auto iChain: trigChain){
    loop_count += 1;
    // each trigger stage loop
    // Legend
    TLegend leg = TLegend(0.25,0.65,0.5,0.93);
    leg.SetTextSize(0.030);
    leg.SetFillStyle(0);
    leg.SetHeader(Form("Collected by %s", (iChain.first).Data()),"");

    TH1F* tmpEvent = (TH1F*)file1->Get("countEvent_" + iChain.first + "_" + iChain.second);
    int NumberOfEvents;
    NumberOfEvents = tmpEvent -> Integral();
    cout << "NumberOfEvents: " << NumberOfEvents << endl;
    double yMax;

    for ( int i = 0; i < nMax; i++){
      TH1F* tmp = (TH1F*)file1->Get("count" + eachTrig[i] + "_" + iChain.first + "_" + iChain.second);
      //tmp -> Scale(NumberOfEvents*25e-09);
      tmp->SetFillColor(histColor[i]);
      //tmp->SetLineColor(histColor[i]);
      if ( i == 0 ) {
        yMax = tmp->GetBinContent(tmp->GetMaximumBin()); 
        tmp -> GetYaxis() -> SetRangeUser( 0, yMax*1.8);
      }
      //if ( i == 5 ) {
      //  NumberOfEvents = tmp -> Integral();
      //  cout << "NumberOfEvents: " << NumberOfEvents << endl;
      //}
      if ( i == 0 ) leg.AddEntry(tmp,Form("%s outputs", (trigInfo[loop_count].first.Data())),"f");
      if ( i == 1 ) leg.AddEntry(tmp,Form("L2MuonSA size in %s", iChain.second.Data()),"f");
      if ( i == 2 ) leg.AddEntry(tmp,Form("L2MuonSA outputs in %s", (iChain.second.Data())),"f");
      //if ( i == 2 ) continue;
      if ( i == 3 ) continue;
      //if ( i == 2 ) leg.AddEntry(tmp,Form("#splitline{offline muons}{(p_{T} > %d GeV && passing %s)}", ((trigInfo[loop_count]).second), iChain.second.Data()),"f");
      if ( i == 4 ) leg.AddEntry(tmp,Form("#splitline{offline muons}{(p_{T} > %d GeV && passing %s)}", ((trigInfo[loop_count]).second), iChain.second.Data()),"f");
      if ( i == 5 ) {
        leg.AddEntry((TObject*)0,Form("NumberOfEvents = %d", NumberOfEvents),"");
        continue;
      }
      if (isFirstEvent) {
        tmp->Draw();
        isFirstEvent = false;;
      }
      if (!isFirstEvent) tmp->Draw("same");
    }
    // for next chain
    isFirstEvent = true;

    leg.Draw();
    c1 -> Print(labelPDF, "pdf");
  }

  c1 -> Print(labelPDF + "]", "pdf");
}
