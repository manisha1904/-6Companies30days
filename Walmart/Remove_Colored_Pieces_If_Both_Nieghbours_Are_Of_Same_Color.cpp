bool winnerOfGame(string colors) {
        int countA=0,countB=0;
        if(colors.length()<3)
            return false;
        for(int i=0;i<colors.length()-2;i++){
            if(colors[i]=='A' && colors[i+1]=='A' && colors[i+2]=='A')
                countA++;
            if(colors[i]=='B' && colors[i+1]=='B' && colors[i+2]=='B')
                countB++;
        }
        return countA>countB;
        
    }
