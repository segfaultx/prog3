#ifndef TEXTFUN_H
#define TEXTFUN_H
	typedef struct listEle{ char suchwort[25];
			char ersetzwort[25];
				struct listEle *next;
	} ListEle;
	struct Fundstelle{ char *stelleImSuchString;
			    ListEle *ersetzung;
	};
	extern ListEle *wordList;
	void addPair(const char *such, const char *ersatz);
	void clearList(void);
	struct Fundstelle find(const char *s);
	int replaceAll(char *s);
	ListEle* getwordlist();
#endif
