#include<string>
#include<map>
#include <vector>

#ifndef parse_gff
#define pare_gff

/* 
GFF3 file format:
Defined at https://github.com/The-Sequence-Ontology/Specifications/blob/master/gff3.md

| Col        | Desc                                                          |
| seqid      | ID of ref                                                     |
| source     | algorithm/operating procedure                                 |
| type       | type of feature                                               |
| start      | 1-based start                                                 |
| end        | start <= end                                                  |
| score      | score of feature                                              |
| strand     | +/-                                                           |
| phase      | Number of bases to be removed with reference to reading frame |
| attributes | list of attributes in the format tag=value;tag-value..        |
*/

class gff3_feature{
public:
  gff3_feature(std::string line);
  int print();
  
  std::string get_seqid();
  std::string get_source();
  std::string get_type();
  uint64_t get_start();
  uint64_t get_end();
  char get_strand();
  int get_phase();
  std::map<std::string, std::string> get_attributes();
  std::string get_attribute(std::string key);

  int set_seqid();
  int set_source();
  int set_type();
  int set_start();
  int set_end();
  int set_strand();
  int set_phase();
  int set_attributes(std::string attr);
private:
  std::string seqid, source, type;
  std::map<std::string, std::string> attributes;
  uint64_t start, end;
  float score;
  char strand;
  int phase;
};

class gff3{
public:
  gff3();
  gff3(std::string path);
  std::vector<gff3_feature> get_features();
  int print();
  int read_file(std::string path);
  std::vector<gff3_feature> query_features(uint64_t pos, std::string type);
  int get_count();
  bool empty();

private:
  std::vector<gff3_feature> features;
  // Flag to see if file has been populated
  bool is_empty;
};

#endif