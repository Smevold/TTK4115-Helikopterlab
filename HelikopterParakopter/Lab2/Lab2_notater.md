# Lab 2
Testplan:
Ha små verdier på alt bortsett fra én, feks q_1=10 og q_2=q_3=r_1=r_2=0.1
Test en etter en

Hver test med step på x og y, istedenfor joystick. 
Test 1:
y går fra 0 til 0,5 etter 5 sek (Joystickutslag: [-1, 1])
x holder seg på 0

Test 2:
y holder seg på 0
x går fra 0 til 0,5 etter 5 sek (Joystickutslag: [-1, 1])

Kommentarer:
Naming scheme: 
q_1_10 betyr at q_1=10, mens resten av verdiene er satt til 0.1
x_05 betyr at x settes til 0.5 etter 5 sek, mens y holdes på 0

q_1_10-x_05 her bevegde pitchen seg masse

q_2_10-x_05 her bevegde pitchen seg nesten ingenting

q_3_10-x_05 ser at elevation har lite oscillasjon i forhold te resten. Lav pitch, men ser tydelig idet den går fra 0 til 0,5. Burde ha høy q_3 for lav oscillasjon

q_3_10-y_05 god respons på y. Traff maks utslag ved ~7,7 sek og den går derfor nedover igjen. 

r_1_10- ga kanskje større oscillasjoner

r_2_10-y_05 ga veldig ustabil travel

r_2_10-x_05 ga veldig ustabil travel, vi måtte gi den et lite "touch" rett etter 5 sek. Vi fikk ikke til å teste denne uten å gi den et touch på en forsvarlig måte.

q_1_5-q_3_8-x_05 ga de beste resultatene til nå.


Vi tenkte feil da vi testet forrige uke. Vektingen er straffing. Så en høyere verdi betyr at den tingen straffes. (Fordi den er en del av kostnadsfunksjonen og vi sier at den koster mer?) ELLER så er det en vekting av straff for at x ikke er der den skal være. I så fall hadde vi riktig.

LQR i forhold til polplassering er veldig nice, fordi du kan vekte spesifikke attributter ved systemet ditt. Om du vil at en attributt skal vektes mer, så kan du gjøre det veldig enkelt. Mens ved polplassering er det mye mer ymse hvordan plasseringen påvirker alle delene av systemet. 

Dag 2:

q_1_5-q_3_8-r_2_8-x_05 veldig treg, men stabiliserte seg pent. Ga lite respons på input i x

Høy q_4 lav q_5 var bedre å svinge. Når den er under startpunktet (elevation) så blir den der idet e_dot_c=0, mens når den er over så faller den ned og oscillerer.

Lav q_4 høy q_5 bedre elevation tracking.

Straffet V_s mindre, og da kunne den holde seg over startpunktet (elevation). Men den gikk alltid litt opp når en stoppet under, og alltid litt ned når en stoppet over.

Lav q_4/5 ~~betyr fremover~~ (lagrede verdier i lab2_2) 1, mens høy betyr 8. Resten av verdiene er q_1=3, q_2=5, q_3=8, r_1=3, r_2=9

Grei følging av pitch og elevation rate. Nøyaktig, men litt tregt.
q1=q2=q4=5, q3=q5=8, r1=3, r2=9

Vi begynte å teste å ta joystick frem/bak (sette elevation_rate) og så slippe (elevation_rate=0). Vi så på Vs, at denne slet med å ta igjen. Idet du slipper endre spenningen seg sterkt i motsatt retning av der du var og så buer den seg tilbake igjen saktere. Den når ikke hele veien tebake. 

q1=q2=5, **q3=6**, q4=5, q5=15, r1=3, r2=6 Denne fungerte bra. Dårlig pitch regulering. Den klarte å bli stabilt veldig høyt over startpunkt.

q1=q2=5, q3=6, q4=5, **q5=10**, r1=3, r2=6 Denne klarte ikke holde høyden sin like bra. Gir mening med mindre straff på akkumulert elevation_rate_error. 

q1=q2=5, q3=6, q4=5, **q5=20**, r1=3, r2=6 Denne oscillerte mer, og holdt ikke høyden bedre. Kan være fordi ved den høye vektingen, så vektes f.eks. q3 mindre. 

**q1=3**, q2=5, q3=6, q4=5, q5=20, r1=3, r2=6 Veldig sakte retting på pitch. Idet den kom ut av balanse brukte den lang tid på å fikse, og pitchen oscillerte.

**q1=9**, q2=5, q3=6, q4=5, q5=20, r1=3, r2=6 Stor oversving på pitch, derfor gikk travel berserk. 

**q1=6**, q2=5, q3=6, q4=5, q5=20, r1=3, r2=6 Da vi lot den stå stille høyt oppe så jobba den såpass med pitch at den etter hvert gjorde seg selv ustabil, og travel gikk berserk.

**q1=4.5**, q2=5, q3=6, q4=5, q5=20, r1=3, r2=6 Fin styring, men ved lengre periode stående stille mister pitchen kontroll. Altså travel gikk berserk. Kan være på grunn av akkumulert pitch error. Siden det tar tid høres det ut som noe med integrerende effekt.

q1=5, q2=5, q3=6, **q4=2**, q5=20, r1=3, r2=6

**q1=3, q2=1**, q3=6, q4=2, q5=20, r1=3, r2=6 Litt roligere idet den mistet kontrollen, men mister fortsatt. Kan vurdere lavere vekting av q4
