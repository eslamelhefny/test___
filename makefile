#this is a comment 

proj=$(proj)
run:$(proj).exe
	@$(proj).exe
	@echo "*******************************Running Done*********************************"

$(proj).i:$(proj).c
	gcc -E $(proj).c -o $(proj).i
	@echo "*******************************preprocessing Done*********************************"

$(proj).s:$(proj).i
	gcc -S $(proj).i 
	@echo "*******************************compilation Done*********************************"

$(proj).o:$(proj).s
	gcc -c $(proj).s 
	@echo "*******************************assembly Done*********************************"
$(proj).exe:$(proj).o
	gcc $(proj).o -o $(proj).exe
	@echo "*******************************linking Done*********************************"


clean_all:
	rm -f $(proj).i $(proj).s $(proj).o $(proj).exe
	@echo "*******************************cleaning Done*********************************"