"""Sammenligningsfigurer til Lab 4 i rapporten. Bruker lab4_kalman_sammenligning fra plot_alle.py,
men med testnumrene fra rapporten i legenden.

  Fig_L4_Qd.pdf          Test 5: Q_d = 1e-6*I mot 1e-2*I (kuttes når IMU-en døde i 1e-2-kjøringen)
  Fig_L4_VanLoan_Offset.pdf  Test 2 uten/med Van Loan, og med Van Loan etter at elevasjons-offseten ble fjernet
  Fig_L4_Bias.pdf        Test 3: uten og med bias-tilstander

Kjør fra repo-rota:  uv run --project plotting python plotting/plot_lab4_report.py
Lager HelikopterParakopter/Figurer_rapport/Fig_L4_*.pdf
"""
import os
import shutil
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from plot_alle import lab4_kalman_sammenligning  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
UT = os.path.join(REPO, "HelikopterParakopter", "Figurer_rapport")

FIGURER = [
    dict(ut="Fig_L4_Qd.pdf",
         forsok=[("2_4_3_Improved_Q_d6_1e-2.mat", r"Test 5: $Q_d = 10^{-2}\,I$", "#E69F00", 1.6, 0.7, 1),
                 ("2_4_3_Improved_Q_d6_1e-6.mat", r"Test 5: $Q_d = 10^{-6}\,I$", "#0072B2", 1.0, 0.95, 2)],
         kutt_ved_imu_dod="2_4_3_Improved_Q_d6_1e-2.mat"),
    # Test 2 uten og med Van Loan (begge med elevasjons-offset), og med Van Loan etter at offseten ble fjernet.
    # Nabokjøringene skiller seg på én ting: 1 -> 2 er bare Van Loan, 2 -> 3 er bare offseten. Ingen bias-tilstander.
    dict(ut="Fig_L4_VanLoan_Offset.pdf",
         forsok=[("2_4_3_Improved_GoodFlight.mat", "Test 2: without Van Loan", "#E69F00", 2.2, 0.6, 1),
                 ("2_4_3_Improved_wVanLoan.mat", "Test 2: with Van Loan", "#CC79A7", 1.2, 0.85, 2),
                 ("2_4_3_Improved_wVanLoan_woOffset.mat", "Offset removed", "#009E73", 1.0, 0.95, 3)]),
    # Test 3: samme oppsett uten og med bias-tilstander, så bare bias-tilstandene skiller kjøringene.
    dict(ut="Fig_L4_Bias.pdf",
         forsok=[("2_4_3_Improved_wVanLoan_woOffset.mat", "Test 3: without bias states", "#E69F00", 1.6, 0.75, 1),
                 ("2_4_3_Improved_wVanLoan_BiasEst.mat", "Test 3: with bias states", "#0072B2", 1.0, 0.95, 2)]),
]

os.makedirs(UT, exist_ok=True)
for fig in FIGURER:
    pdf = lab4_kalman_sammenligning(**fig)  # lagres i Lab4-mappa
    mal = os.path.join(UT, fig["ut"])
    shutil.move(pdf, mal)
    print("Lagret", os.path.relpath(mal, REPO))
