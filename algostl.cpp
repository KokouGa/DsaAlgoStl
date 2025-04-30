#include <iostream>
#include<vector>
#include <string>
#include <algorithm> // sort, min_element, max_element


int main(int argc, char const *argv[])
{
	std::vector<int> nombres  = {12, 34, 51, 2, 9, 1, 52, 37, 27};


	for (size_t i = 0; i < nombres.size(); ++i) {
    std::cout << nombres[i] << " ";
	}

	std::sort(nombres.begin(), nombres.end());

	for (int val : nombres) {
    std::cout << val << " ";
	}

	for (auto it = nombres.begin(); it != nombres.end(); ++it) {
    std::cout << *it << " ";
	}
     
	std::sort(v.begin(), v.end());               // Tri croissant
	std::reverse(v.begin(), v.end());            // Inverser
	auto it = std::find(v.begin(), v.end(), 42);


	int minimum = *std::min_element(nombres.begin(), nombres.end());
    int maximum = *std::max_element(nombres.begin(), nombres.end());



    struct Personne {
    std::string nom;
    int age;
	};

	std::vector<Personne> personnes = {{"Alice", 25}, {"Bob", 20}};
	std::sort(personnes.begin(), personnes.end(), [](const Personne& a, const Personne& b) {
    		return a.age < b.age; // Tri par âge croissant
	});
    
    // Stable sort
    std::vector<std::pair<int, char>> pairs = {{1, 'a'}, {2, 'b'}, {1, 'c'}};
    std::stable_sort(pairs.begin(), pairs.end());
     

    struct Employe {
    std::string nom;
    std::string departement;
    int anciennete; // en années
		};




    std::vector<Employe> employes = {
        {"Alice", "IT", 3},
        {"Bob", "RH", 2},
        {"Claire", "IT", 1},
        {"David", "RH", 2}
    };

    // Tri par département, puis par ancienneté (en conservant l'ordre d'insertion)
    std::stable_sort(employes.begin(), employes.end(), [](const Employe& a, const Employe& b) {
        if (a.departement != b.departement)
            return a.departement < b.departement;
        return a.anciennete < b.anciennete;
    });

    auto multiFieldComparator = [](const auto& a, const auto& b) {
    return std::tie(a.statut, a.urgence, a.date) 
         < std::tie(b.statut, b.urgence, b.date);
	};
    
    template<typename It, typename Compare>
	void smart_stable_sort(It begin, It end, Compare cmp) {
    // Vérifie si la plage contient des doublons
    	bool has_duplicates = std::adjacent_find(begin, end, 
        [&](const auto& a, const auto& b) { return !cmp(a, b) && !cmp(b, a); }) != end;
    
    	has_duplicates ? std::stable_sort(begin, end, cmp)
                   : std::sort(begin, end, cmp);
		}

// Utilisation :
		smart_stable_sort(commandes.begin(), commandes.end(), multiFieldComparator);  
	return 0;
}