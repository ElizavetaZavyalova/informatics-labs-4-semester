#pragma once
#include <thread>
#include <chrono>
#include <iostream>
#include <conio.h>
///#include "laba2_3_4.h"

namespace blocks {
	bool _buf(bool first) {
		return first;
	}
	bool _no_buf(bool first) {
		return !first;
	}
	bool _and(bool first, bool second, bool third=1) {
		return first & second & third;
	}
	bool _no_and(bool first, bool second) {
		return !(first & second);
	}
	bool _or(bool first, bool second, bool third = 0, bool fourth=0) {
		return first | second| third;
	}
	bool _no_or(bool first, bool second) {
		return !(first|second);
	}
	bool _exclusive_or (bool first, bool second) {
		return (first^second);
	}
}

namespace ALU {
	bool alu(bool F0, bool F1, bool A, bool B, bool &INC, bool ENA = 1, bool ENB = 1) {
		bool INVA = 0;
		bool S1_ = blocks::_exclusive_or(blocks::_and(A, ENA), INVA);
		bool S2_ = blocks::_and(B, ENB);
		///
		bool D1_ = blocks::_and(blocks::_no_buf(F0), blocks::_no_buf(F1));
		bool D2_ = blocks::_and(blocks::_no_buf(F0), F1);
		bool D3_ = blocks::_and(F0, blocks::_no_buf(F1));
		bool D4_ = blocks::_and(F0, F1);
		///
		bool _L1 = blocks::_and(S1_, S2_);
	    bool _L2= blocks::_or(S1_, S2_);
		bool _L3 = blocks::_no_buf(S2_);
		///
		bool L1_ = blocks::_and(_L1, D1_);
		bool L2_ = blocks::_and(_L2, D2_);
		bool L3_ = blocks::_and(_L3, D3_);
		///
		bool _P_1 = blocks::_exclusive_or(S1_, S2_);
		bool _P_S_1 = blocks::_and(S1_, S2_, D4_);
		///
		bool _P_2 = blocks::_exclusive_or(_P_S_1, INC);
		//
		bool _P_S_2 = blocks::_and(_P_S_1, INC, D4_);
		bool P_= blocks::_and(_P_2, D4_);
		INC= blocks::_or(_P_S_1, _P_S_2);
		return blocks::_or(L1_, L2_, L3_, P_);
	}
	void alu8(const int count=8) {
		std::cout << "F0:";
		bool F0;
		std::cin >> F0;
		std::cout << "F1:";
		bool F1;
		std::cin >> F1;
		bool INC = 0;
		for (int i = 0; i < count; i++) {
			std::cout << "A:";
			bool A;
			std::cin >> A;
			std::cout << "B:";
			bool B;
			std::cin >> B;
			std::cout << alu(F0, F1, A, B, INC)<<"\n";

		}
		if (INC) {
			std::cout << INC;
		}
	}
};

namespace latch {
	void incrementer(bool& flag, bool &L)
	{
		while (flag)
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
			L=!L;
		}
	}
	void simulator() {
		bool D;
		bool Q1= 1;
		bool Q2 = 0;
		bool L = 0;
		bool flag = true;
		std::thread th(incrementer, std::ref(flag), std::ref(L));
		while (true) {
			std::cout << "D:";
			std::cin >> D;
			//L = 1;
			while (!L);
				bool T = L;
				bool AND1 = blocks::_and(D, T);
				bool AND2 = blocks::_and(blocks::_no_buf(D), T);
			    bool S1 = blocks::_no_or(AND1, Q2);
				bool S2 = blocks::_no_or(AND2, Q1);
				Q2 = S2;
				Q1 = S1;
			std::cout << "Q1:" << Q1 << "\n";
			std::cout << "Q2:" << Q2 << "\n";
		}
		flag = false;
		th.join();
	}

}