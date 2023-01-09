// Using the Jumble Word Solver you found 974 words with the letters, RESOLUTION.


// below is the c++ code to implement it!
#include <bits/stdc++.h>
using namespace std;
 
// For searching in all 8 direction
int x[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
int y[] = { -1,  0,  1, -1, 1, -1, 0, 1 };
 
// This function searches in
// all 8-direction from point
// (row, col) in matrix[][]
bool search2D(char *grid, int row, int col,
               string word, int R, int C)
{
    // If first character of word doesn't
    // match with given starting point in grid.
    if (*(grid+row*C+col) != word[0])
        return false;
 
    int len = word.length();
 
    // Search word in all 8 directions
    // starting from (row, col)
    for (int dir = 0; dir < 8; dir++) {
        // Initialize starting point
        // for current direction
        int k, rd = row + x[dir], cd = col + y[dir];
 
        // First character is already checked,
        // match remaining characters
        for (k = 1; k < len; k++) {
            // If out of bound break
            if (rd >= R || rd < 0 || cd >= C || cd < 0)
                break;
 
            // If not matched,  break
            if (*(grid+rd*C+cd) != word[k])
                break;
 
            // Moving in particular direction
            rd += x[dir], cd += y[dir];
        }
 
        // If all character matched, then value of k must
        // be equal to length of word
        if (k == len)
            return true;
    }
    return false;
}
 
// Searches given word in a given
// matrix in all 8 directions
void patternSearch(char *grid, string word,
                  int R, int C)
{
    // Consider every point as starting
    // point and search given word
    for (int row = 0; row < R; row++)
        for (int col = 0; col < C; col++)
            if (search2D(grid, row, col, word, R, C))
                cout <<word << " _found at_  "
                     << row << ", "
                     << col << endl;
}
 
// Driver program
int main()
{// our 2d matrix..
    char matrix[14][14]{
{'v','m','x','l','x','n','k','a','x','u','t','o','g','v'},
{'r','b','f','s','x','m','c','j','q','t','m','n','l','u'},
{'x','u','w','o','s','a','e','z','n','e','s','g','g','e'},
{'v','s','b','l','t','s','i','u','e','n','f','r','y','n'},
{'c','h','m','o','o','j','u','k','w','s','s','u','n','l'},
{'s','n','b','o','d','i','q','f','w','i','i','o','e','i'},
{'o','e','l','e','t','f','z','k','z','l','g','r','t','s'},
{'l','p','f','n','r','t','n','e','i','r','o','t','s','t'},
{'u','d','e','i','e','f','w','r','h','d','a','n','i','a'},
{'t','b','u','t','s','s','b','d','j','w','c','i','l','o'},
{'i','i','e','u','n','b','e','r','o','s','i','o','n','i'},
{'o','p','b','o','i','o','s','t','o','l','e','a','p','o'},
{'n','f','k','r','q','i','b','c','r','a','q','a','u','y'},
{'q','i','m','l','c','l','i','s','t','e','n','x','j','c'}
};
   
string jumble[]={
//     "resolution", // 10 len word
//     "outliners", // 9 len word
//     "elutions", "insulter", "looniest",  // 8 len words
// "louriest", "lustrine","nitreous", "oestriol", "oilstone",
// "outliers", "outliner", "outlines", "outsnore", 
// "retinols", "risoluto", "routines", "snootier", "snoutier",
//  "solution", "torulins", "torulose", "troolies", "turnsole",
 // 7 len word
// "elusion", "elution","elutors", "enroots", "entoils", "erosion", "estriol",
// "isotone", "isotron", "lentors", "lentous", "lienors","linters", "lionets",
// "loiters", "loonier", "loonies", "looters", "loriots", "lornest", "lotions",
// "louries", "lousier", "luniest", "lustier", "luteins", "neosoul", "nerolis", 
// "nitroso", "nitrous", "norites", "nostril", "noursle", "nutsier", "oestrin", 
// "oilnuts", "onerous", "onliest", "oolites", "ooriest", "orients", "orioles", 
// "ostiole", "ouriest", "outlers", "outlier", "outlies", "outline", "outsole", 
// "retinol", "retools", "riotous", "rooties", "rootles", "rosinol", "routine", 
// "ruliest", "runlets", "rutiles", "slinter", "snirtle", "soilure", "soliton", 
// "sonlier", "sootier", "stonier", "stoolie", "stourie", "surloin", "tenours", 
// "tersion", "toilers", "tonsure", "toolers", "toolies", "toonies", "toories", 
// "torsion", "torulin", "touries", "tousier", "triones", "triunes", "troilus",
// "troolie", "troules", "turions", "ultions", "uniters", "unloose", "unroost", 
// "unroots", "unsoote", "untiles", "urinose", "utensil",

// 6 letter word 
// "elints", "eloins", "elutor", "enlist", "enrols", "enroot", "ensoul", "entoil",
// "erinus", "esloin", "estrin", "inerts", "inlets", "insert", "insole", "insoul", 
// "insult", "insure", "intels", "inters", "intros", "intuse", "inures", "irones", 
// "lentor", "lentos", "lesion", "lienor", "liners", "linter", "lionet", "listen", 
// "lister", "liters", "litres", "loiter", "loners", "looies", "loonie", "loosen", 
// "looser", "loosie", "looten", "looter", "lories", "loriot", "lotion", "louies", 
// "loures", "lourie", "louser", "luiten", "lunets", "lunier", "lunies", "luster", 
// "lustre", "lutein", "luters", "neroli", "nerols", "nestor", "niters", "nitres", 
// "nitros", "nooser", "norite", "norsel", "nosier", "nostoi", "nostro", "noters", 
// "notour", "noules", "nousle", "nursle", "oilers", "oilnut", "oleins", "oolite", 
// "oosier", "oriels", "orient", "oriole", "orison", "orlons", "ostler", "otiose", 
// "ouster", "outers", "outler", "outlie", "outros", "outsin", "relist", "reoils", 
// "result", "retool", "roesti", "roneos", "rontes", "rootle", "rotoli", "rotons", 
// "rouens", "roules", "routes", "runlet", "rusine", "rustle", "rutile", "rutins", 
// "senior", "seroon", "silent", "sinter", "solein", "solion", "solito", "solute", 
// "soneri", "sooler", "sooner", "sortie", "souter", "soutie", "sterol", "stolen", 
// "stolon", "stoner", "stoure", "strine", "suiter", "suitor", "sunlit", "sutile",
// "sutler", "telson", "tenors", "tenour", "tensor", "tenuis", "tilers", "tinsel", 
// "tiroes", "toiler", "toiles", "toison", "toners", "tonier", "tonies", "tonsil", 
// "tonsor", "tooler", "toolie", "toonie", "toorie", "tories", "torose", "torous", 
// "torsel", "toruli", "tourie", "touser", "tousle", "triens", "trines", "triols", 
// "triose", "trisul", "triune", "trones", "troule", "trouse", "tuiles", "tuners", 
// "tunier", "turion", "ulster", "ultion", "uniter", "unites", "unlost", "unrest", 
// "unroot", "unties", "untile", "urines", "urites", "ursine", "ustion", "utiles",

// 5 letter jumble words using the letters RESOLUTION
// "elint", "eloin", "elsin", "enlit", "enols", "enrol", "eorls", "eosin", "estro", 
// "etuis", "euros", "eusol", "ileus", "inert", "inlet", "inset", "intel", "inter", 
// "intro", "inure", "inust", "irone", "irons", "islet", "istle", "leirs", "lenis", 
// "lenos", "lenti", "lento", "liens", "liers", "lieus", "liner", "lines", "linos", 
// "lints", "lions", "lirot", "liter", "lites", "litre", "loins", "loirs", "loner", 
// "looie", "loons", "loose", "loots", "lores", "loris", "losen", "loser", "lotes", 
// "lotos", "lotus", "louie", "louis", "louns", "loure", "lours", "louse", "louts", 
// "lunes", "lunet", "lunts", "lures", "luser", "luter", "lutes", "neist", "nelis", 
// "nerol", "nerts", "nirls", "niter", "nites", "nitre", "nitro", "noels", "noils",
// "noirs", "noise", "noles", "nolos", "nooit", "noose", "noris", "noser", "noter",
// "notes", "noule", "nouls", "nurls", "nurse", "nutso", "oiler", "oints", "olein",
// "olent", "oleos", "olios", "oners", "onset", "oonts", "oorie", "oriel", "orles", 
// "orlon", "ornis", "osier", "ouens", "ourie", "ousel", "outer", "outre", "outro", 
// "reins", "reist", "relit", "renos", "rents", "reoil", "resin", "resit", "resto", 
// "riels", "riles", "rines", "rinse", "riots", "risen", "rites", "roils", "roins", 
// "roist", "roles", "roneo", "rones", "ronte", "ronts", "roons", "roose", "roost", 
// "roots", "roset", "rosin", "rosit", "rosti", "rotes", "rotis", "rotls", "roton", 
// "rotos", "rouen", "roues", "roule", "rouls", "rouse", "roust", "route", "routs", 
// "ruins", "rules", "runes", "runts", "rutin", "senor", "senti", "serin", "seron", 
// "seton", "sient", "sieur", "silen", "siler", "siren", "slier", "sloot", "sluit", 
// "snirt", "snool", "snoot", "snore", "snort", "snout", "solei", "soler", "solon", 
// "soole", "soote", "sorel", "sotol", "steil", "stein", "steno", "stern", "stile", 
// "stire", "stole", "stoln", "stone", "stool", "stoor", "store", "stoun", "stour", 
// "sture", "suent", "suint", "suite", "sutor", "teils", "teins", "teloi", "telos", 
// "tenor", "terns", "tiers", "tiler", "tiles", "tines", "tires", "tirls", "tiros", 
// "toile", "toils", "toise", "toles", "tolus", "toner", "tones", "tonus", "tools", 
// "toons", "tores", "toros", "torse", "torsi", "torso", "torus", "touns", "tours", 
// "touse", "tries", "trine", "trins", "triol", "trios", "trois", "trone", "trons", 
// "trues", "tuile", "tules", "tulsi", "tuner", "tunes", "turns", "unite", "units", 
// "unlet", "unlit", "unset", "untie", "until", "urent", "urine", "urite", "urson", 
// "uteri", "utile",

// //4 letter jumble words using the letters RESOLUTION
// "elts", "enol", "ents", "eons", "eorl", "erns", "eros", "erst", "etui", "euoi", "euro", 
// "inro", "into", "ions", "ires", "iron", "isle", "iure", "leir", "leis", "leno", "lens", 
// "lent", "lest", "lets", "lien", "lier", "lies", "lieu", "line", "lino", "lins", "lint", 
// "lion", "lire", "list", "lite", "lits", "litu", "loin", "loir", "lone", "loon", "loor", 
// "loos", "loot", "lore", "lorn", "lose", "lost", "lote", "loti", "loto", "lots", "loun", 
// "lour", "lous", "lout", "lues", "luit", "lune", "luns", "lunt", "lure", "lurs", "lust", 
// "lute", "nest", "nets", "nies", "nils", "nirl", "nite", "nits", "noel", "noes", "noil", 
// "noir", "nole", "nolo" ,"nori", "nose", "note", "noul", "nous", "nout", "nurl", "nurs", 
// "nuts", "oils", "oint" ,"oleo", "oles", "olio", "oner", "ones", "onie", "onos", "onst",
// "onto", "onus", "oons" ,"oont", "oose", "oots", "ores", "orle", "orts", "ourn", "ours",
// "oust", "outs", "rein" ,"reis", "reno", "rens", "rent", "reos", "rest", "rets",
// "riel", "rile", "rine" ,"rins", "riot", "rise", "rite", "rits", "roes", "roil",
// "roin", "role", "rone" ,"ront", "roon", "roos", "root", "rose", "rost", "rote",
// "roti", "rotl", "roto" ,"rots", "roue", "roul", "rout", "rues", "ruin", "rule" ,"rune", 
// "runs", "runt", "ruse" ,"rust", "ruts", "seil", "seir", "sent", "sien", "sile" ,"silo", 
// "silt", "sine", "sire" ,"site", "slit", "sloe", "slot", "slue", "slur", "slut" ,"snit", 
// "snot", "soil", "sole" ,"soli", "solo" ,"sone", "sool", "soon", "soot", "sore" ,"sori", 
// "sorn", "sort", "soul" ,"sour", "sout" ,"sten", "stie", "stir", "stun", "suer" ,"suet", 
// "suit", "suni", "sure" ,"teil", "tein" ,"tels", "tens", "tern", "tier", "ties" ,"tile", 
// "tils", "tine", "tins" ,"tire", "tirl" ,"tiro", "toes", "toil", "tole", "tolu" ,"tone", 
// "tons", "tool", "toon" ,"tore", "tori" ,"torn", "toro", "tors", "tose", "toun" ,"tour", 
// "tres", "trie", "trin" ,"trio", "tron" ,"trou", "true", "tuis", "tule", "tune" ,"tuns", 
// "turn", "ules", "unis" ,"unit", "unto" ,"ures", "urns", "user", "utes", "utis",


// //3 letter jumble words using the letters RESOLUTION
// "els", "elt", "ens", "eon", "ern", "ers", "est", "ins", "ion", "ios", "ire" ,"iso", "its", "lei",
// "les", "let", "leu", "lie", "lin", "lis", "lit", "loo", "lor" ,"los", "lot", "lou", "lun", 
// "lur", "net", "nie", "nil", "nis", "nit", "noo", "nor", "nos" ,"not", "nur", "nus", "nut", 
// "oes", "oil", "ois", "ole", "one", "ono", "ons", "oon", "oor" ,"oos", "oot", "ore", "ors", 
// "ort", "ose", "our", "ous", "out", "rei", "ren", "reo", "res" ,"ret", "rin", "rit", "roe", 
// "roo", "rot", "rue", "run", "rut", "sei", "sel", "sen", "ser" ,"set", "sin", "sir", "sit", 
// "sol", "son", "sot", "sou", "sri", "sue", "sui", "sun", "sur" ,"tel", "ten", "tes", "tie", 
// "til", "tin", "tis", "toe", "ton", "too", "tor", "tui", "tun" ,"ule", "uni", "uns", "ure", 
// "urn", "use" ,"ute", "uts",

// 2 letter jumble words using the letters RESOLUTION
"el", "en", "eo", "er", "es", "et", "in", "io", "is", "it", "li", "lo", "ne", "no", "nu", "oe", "oi", "on", 
"oo", "or", "os" ,"ou" ,"re" ,"si" ,"so", "st" , "te" ,"ti", "to" ,"un", "ur", "us" ,"ut"
};

int no_of_element=sizeof(jumble)/sizeof(jumble[0]);

for(int i=0;i<no_of_element;i++){
    
    patternSearch((char *)matrix, jumble[i], 14, 14);
   }
return 0;
}