# oop-cj
Course repo for Objekterienterad programmering och design.

## Tips and tricks


## Question box

### När vill vi skriva en klass, och när vill vi skriva en struct?


### Hur kan man kontrollera om en sträng är tom?
Låt säga att vi har en funktion som tar in ett namn, d.v.s. en string, och skriver ut "Hej <namn>!".
Innan vi skriver ut eller gör något annat med strängen, vill vi kontrollera att strängen inte är tom. I C++ kan vi använda string-metoden _empty()_, som returnerar true eller false. Om längden på strängen är 0, så returneras empty() alltså true. Samma sak som _name.length == 0_.
```cpp
void print_name(const std::string& name) {
  if (name.empty())
  {
    return; // Skriver inte ut något om strängen är tom. Avslutar funktionen med return;
  }
  else
  {
    std::cout << "Hej " << name << "!" << std::endl;
  }
}
```

### Kostar det något att ha en abstrakt klass som delar beteende med ärvande klasser?
Ja, men kostnaden är oftast marginell och motiverad.
En abstrakt klass är en designkonstruktion, inte en runtime-funktion i sig. Den kan innehålla både:

Abstrakta metoder: kräver implementering i subklasser, ger ingen direkt minneskostnad.

Gemensam implementation (kod): betyder att kod finns lagrad i programmet, men den behöver inte dupliceras i subklasser – de ärver den.

Kostnader:

Ett vtable (virtuellt metodbord) skapas för klasser med virtuella metoder, vilket tar lite minne.

Virtuella anrop kan vara något långsammare än statiska funktionsanrop (men i modern hårdvara är detta obetydligt).

Däremot minskar du ofta duplicerad kod och förbättrar underhållbarhet, vilket är en nettovinst.

Slutsats:
Abstrakta klasser används för att skapa logisk struktur och återanvändning. Den lilla tekniska overheaden är nästan alltid värd det om hierarkin är välmotiverad.

### Hur utvecklar man bibliotek som kan återanvändas i andra projekt?

### Vad innebär RTTI? Är det tecken på dålig design?
RTTI = Run-Time Type Information
Ett system i C++ som låter dig ta reda på ett objekts verkliga typ under körning, t.ex. med dynamic_cast eller typeid.

Är det dåligt?

Att du behöver RTTI kan ibland vara en signal på att din design förlitar sig för mycket på typkontroll vid runtime istället för polymorfi vid compile-time.

Men RTTI i sig är inte dåligt, det är ett verktyg som har sitt syfte i vissa situationer. Det blir problem först när det används som ersättning för bra objektorienterad design.

God användning:
Logging, debugging, plugin-laddning, seriell/deseriell kod.

Dålig användning:
Upprepade dynamic_cast i produktionslogik för att avgöra "vilken typ" objektet är i stället för att använda virtuella funktioner.

Slutsats:
RTTI är inte tecken på dålig design – men överanvändning kan vara en röd flagga.

### När behöver vi en constructor?
En konstruktor behövs när:
- Ett objekt behöver initialiseras i ett definierat tillstånd.
- Medlemsvariabler kräver värden vid skapande.
- Du vill garantera korrekt användning av objektet (t.ex. att resurser allokeras).
- Du vill förhindra objekt i "odelvis initierat" tillstånd.

Implicit vs explicit:

Om inga resurser behöver initieras kan du använda en default-konstruktor genererad av kompilatorn.
Om du har komplex initialisering eller vill tvinga användaren att ange parametrar – då definierar du en egen konstruktor.

Exempel:
```cpp
class FileHandler {
public:
    FileHandler(const std::string& filename) {
        file = fopen(filename.c_str(), "r");
        if (!file) throw std::runtime_error("Could not open file.");
    }
private:
    FILE* file;
};
```

Här måste vi ha en constructor, annars kan objektet bli oanvändbart eller farligt.

Slutsats:
En konstruktor behövs när du vill kontrollera hur objektet skapas, säkerställa korrekt initialisering eller uppfylla RAII-principen (Resource Acquisition Is Initialization).
