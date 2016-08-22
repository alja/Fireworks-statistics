
root [2] t.ReadFile("$HOME/2016.txt", "t/I:os/C:pkg/C")
Error in <TTree::ReadFile>: Cannot open file: $HOME/2016.txt
(Long64_t) 0
root [3] t.ReadFile("/Users/alja/2016.txt", "t/I:os/C:pkg/C")
(Long64_t) 13930
root [4] 
root [4] t.Draw("t", "t>1450e6") 
Info in <TCanvas::MakeDefCanvas>:  created default TCanvas with name c1
(Long64_t) 13930
root [5] 
root [5] t.Draw("t:os", "t>1450e6", "h") 
(Long64_t) 13930
root [6] t.Draw("t:os", "t>1450e6", "lego") 
(Long64_t) 13930
root [7] t.Draw("t:os", "t>1450e6", "lego2") 
(Long64_t) 13930
root [8] t.Draw("t:os") 
root [9] t.Draw("t:os", "t", "lego2") 
(Long64_t) 13930
root [10] t.Draw("t:pkg", "t", "lego2") 
(Long64_t) 13930
root [11] t.Draw("os:t/3.14e7", "", "lego2")
(Long64_t) 13930
root [12] t.Draw("os:t-1451598406/3.14e7", "", "lego2")
(Long64_t) 13930
root [13] 
root [13] t.Draw("os:t-1451598406", "", "lego2")
(Long64_t) 13930
root [14] t.Draw("os:(t-1451598406)/(24*3600)", "", "lego2")
(Long64_t) 13930
root [15] t.Draw("os:((t-1451598406)/(24*3600))", "", "lego2")
(Long64_t) 13930
root [16] t.Draw("os:((t-1451598406)/(24*3600*30))", "", "lego2")
(Long64_t) 13930
root [17] t.Draw("t:pkg", "t", "lego2") 
(Long64_t) 13930
root [18] t.Draw("os:(t-1451598406)/(24*3600)", "", "lego2")
(Long64_t) 13930
root [19] t.Draw("os:(t-1451598406)/(24*3600*30)", "", "lego2")
(Long64_t) 13930
root [20] h=new TH2F("name","title", 12, 0, 12, 2, 0, 2);
root [21] t.Draw("os:(t-1451598406)/(24*3600*30)>>name", "", "lego2")
(Long64_t) 13930
root [22] h->GetXaxis()->SetTitle("Boboo [s]")
root [23] h=new TH2F("name","title", 48, 0, 12, 2, 0, 2);
Warning in <TROOT::Append>: Replacing existing TH1: name (Potential memory leak).
root [24] t.Draw("os:(t-1451598406)/(24*3600*30)>>name", "", "lego2")
(Long64_t) 13930
root [25] h->GetXaxis()->SetTitle("Boboo [s]")
root [26] h->GetXaxis()->SetTitle("Months [s]")
root [27] t.Draw("os:(t-1451598406)/(24*3600*30)>>name", "", "lego2")
(Long64_t) 13930
root [28] t.Draw("pkg:(t-1451598406)/(24*3600*30)>>name", "", "lego2")
(Long64_t) 13930
root [29]  hp=new TH2F("name","pkg", 48, 0, 12, 2, 0, 2);
Warning in <TROOT::Append>: Replacing existing TH1: name (Potential memory leak).
root [30]  hp=new TH2F("pkg","pkg", 48, 0, 12, 2, 0, 2);
root [31] t.Draw("pkg:(t-1451598406)/(24*3600*30)>>name", "", "lego2")
(Long64_t) 13930
