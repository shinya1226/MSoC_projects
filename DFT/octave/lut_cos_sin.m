clear all
close all

size = 129;
fp = fopen("lut_cos.txt","w+");
for i=1:size
  for j=1:size
    fprintf(fp,"%12f,",cos(3.141592653589/128*(i-1)*(j-1)));
  endfor
    fprintf(fp,"\n");
endfor

fr = fopen("lut_sin.txt","w+");
for i=1:size

  for j=1:size
    fprintf(fr,"%12f,",sin(3.141592653589/128*(i-1)*(j-1)));
  endfor
  fprintf(fr,"\n");
endfor
fclose(fp);
fclose(fr);