
void  roiEta(){
  TF1 *roiEta_5  = new TF1("roiEta_5",  "( (5000*sin(2*atan(exp(-x))))/2. )*(1./(tan(2*atan(exp(-x-0.05)))) - 1./(tan(2*atan(exp(-x+0.05)))))",  0, 2.5);
  TF1 *roiEta_8  = new TF1("roiEta_8",  "( (8000*sin(2*atan(exp(-x))))/2. )*(1./(tan(2*atan(exp(-x-0.05)))) - 1./(tan(2*atan(exp(-x+0.05)))))",  0, 2.5);
  TF1 *roiEta_10 = new TF1("roiEta_10", "( (10000*sin(2*atan(exp(-x))))/2. )*(1./(tan(2*atan(exp(-x-0.05)))) - 1./(tan(2*atan(exp(-x+0.05)))))", 0, 2.5);

  roiEta_5->SetTitle(";#eta;#Delta Z [mm]");
  roiEta_5->SetLineWidth(4);
  roiEta_5->GetYaxis()->SetRangeUser(0,1500);
  roiEta_5->Draw("");

  roiEta_8->SetLineColor(2);
  roiEta_8->SetLineWidth(4);
  roiEta_8->Draw("same");

  roiEta_10->SetLineColor(4);
  roiEta_10->SetLineWidth(4);
  roiEta_10->Draw("same");

  gPad->SetGrid();
  gStyle->SetLegendBorderSize(0);

  TLegend *leg = new TLegend(0.72,0.22,0.9,0.42);
  leg->AddEntry(roiEta_5,"R = 5 [m]","l");
  leg->AddEntry(roiEta_8,"R = 8 [m]","l");
  leg->AddEntry(roiEta_10,"R = 10 [m]","l");
  leg->SetFillStyle(0);
  leg->Draw("same");

}
