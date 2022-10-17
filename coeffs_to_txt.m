format long

f_num = single(Num);

fileID = fopen('coeffs_30k.txt','w');
fprintf(fileID,'const float32_t firCoeffs32[NUM_TAPS_ARRAY_SIZE] = {\n');

fprintf(fileID,'%f,%f,%f,%f,%f,%f,%f,%f,\n',f_num(1),f_num(2),f_num(3),f_num(4),f_num(5),f_num(6),f_num(7),f_num(8));
fprintf(fileID,'%f,%f,%f,%f,%f,%f,%f,%f,\n',f_num(9),f_num(10),f_num(11),f_num(12),f_num(13),f_num(14),f_num(15),f_num(16));
fprintf(fileID,'%f,%f,%f,%f,%f,%f,%f,%f,\n',f_num(17),f_num(18),f_num(19),f_num(20),f_num(21),f_num(22),f_num(23),f_num(24));
fprintf(fileID,'%f,%f,%f,%f,%f,%f,%f,%f,\n',f_num(25),f_num(26),f_num(27),f_num(28),f_num(29),f_num(30),f_num(31),f_num(32));
fprintf(fileID,'%f,%f,%f,%f,%f,%f,%f,%f,\n',f_num(33),f_num(34),f_num(35),f_num(36),f_num(37),f_num(38),f_num(39),f_num(40));
fprintf(fileID,'%f,%f,%f,%f,%f,%f,%f,%f\n',f_num(41),f_num(42),f_num(43),f_num(44),f_num(45),f_num(46),f_num(47),f_num(48));
fprintf(fileID,'};');
fclose(fileID);