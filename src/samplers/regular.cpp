#include "../../include/regular.h"
#include <cmath>

Regular::Regular(int samples, int sets) :
    Sampler(samples, sets) {
	gen_samples();
}


void Regular::gen_samples(){
	int n = static_cast<int>(sqrt(n_samples));
	for (int j = 0; j < n_sets; j++)
		for (int p = 0; p < n; p++)		
			for (int q = 0; q < n; q++){
                double data[] = {(q + 0.5) / n, (p + 0.5) / n};
                Tuple<2> sp(data);
                samples.push_back(sp);
            }

}
