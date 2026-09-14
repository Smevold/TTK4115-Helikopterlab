# Testplan:

Ha små verdier på alt bortsett fra én, feks q_1=10 og q_2=q_3=r_1=r_2=0.1
Test en etter en

Hver test med step på x og y, istedenfor joystick. 
Test 1:
y går fra 0 til 0,5 etter 5 sek (Joystickutslag: [-1, 1])
x holder seg på 0

Test 2:
y holder seg på 0
x går fra 0 til 0,5 etter 5 sek (Joystickutslag: [-1, 1])

## Kommentarer:
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