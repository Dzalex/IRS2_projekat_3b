# IRS2_projekat_3b
 - Projekat 3b iz Integrisanih Racunarskih Sistema 2 na master studijama odseka za Elektroniku i Digitalne sisteme 2022/2023 godine.

### Generator funkcija:
 - DAC, DMA, generator standardnih talasnih oblika čiji parametri se zadaju preko potenciometara ili tastera. OLED opciono za neki prikaz(loopback adc očitavanje i prikaz).
 
 # Izveštaj
 ### DAC i DMA
 Kako bi se ispunio glavni zahtev projekta, tj. generisanje talasnih oblika, potrebno je konfigurisati i koristiti DAC, a transfer podataka iz memorije ka konvertoru treba realizovati pomoću DMA. Da bi se to uradilo potrebno je u memoriji odvojiti prostor za odbirke koji će biti preneti konvertoru i ovo je obavljeno u fajlu lookup_table.h. Podešavanje DAC-a je takvo da on radi u Normal Mode-u, i Trriger mu je Out event Timer-a 6. DMA je podešen tako da cirkularno prosleđuje odbirke iz table kada su potrebni periferiji. DAC se pokreće funkcijom `HAL_DAC_Start_DMA()`, kako bi se prenos desio pomoću DMA.
 
 ### Tajmeri
 U projektu se koriste tri tajmera (TIM1, TIM6 i TIM17). 
 #### TIM1
 Koristi se za periodično pokretanje ADC konverzije, radi provere statusa potenciometra. Podešen je da to uradi putem Out eventa svako 100ms.
 #### TIM6
 Ovaj tajmer je već spomenut i koristi se kao vremenska osnova za generisanje signala. Vrednost koja je podešena u njegovom Counter Period registru direktno određuje frekvenciju izlaznog signala. TIM6 je podešen tako da ima fiksan Prescaler od 9, a u softveru je moguće promeniti vrednost Counter Period-a. Podešen mu je trigger Event, tako da pri isteku DAC je obavešten da može započeti sledeću konverziju. Promena frekvencije u softweru se dešava u sklopu funkcije `Set_Generator_Frequency()`.
 #### TIM17
 Da bi se izvršilo debounsiranje dva tastera (SW1 i SW2) potrebno je posle inicijalnog pritiska na neki, naknadno proveriti njihov status i samo jednom aktivirati željenu proceduru (u ovom slučaju promenu moda, waveforma, generatora - `Set_Generator_Mode()`) i vreme čekanja je 70ms. 
 
 ### ADC
 Da bi se podesila frekvencija izlaznog signala korisit se potenciometar POT1, koji je povezan na ADC1, ulaz 6. Kada se konverzija obavi, poziva se prekidna rutina u sklopu koje se podešava nova frekvencija.
 
 ### I2C
 Za komunikaciju sa OLED disiplejem koristi se I2C 2 koji radi u standardnom modu na 100kHz. Implementacija drivera za ovaj displej je u sklopu Submodula stm32-ssd1306.
 
 
