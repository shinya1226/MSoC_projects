clear all
close all

x = imread("test_1080p.bmp");
fid = fopen("test_1080p.dat","wb+");

cnt = 1;
for j=1:1920
  for i=1:1080
    B = int2str(x(i,j,3));
    fwrite(fid,strcat(B,"\n"));
    G = int2str(x(i,j,2));
    fwrite(fid,strcat(G,"\n"));
    R = int2str(x(i,j,1));
    fwrite(fid,strcat(R,"\n"));
  endfor
endfor
fclose(fid);


