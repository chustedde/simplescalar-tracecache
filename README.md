# Filtered Trace Cache using SimpleScalar

This is from a group project I worked on quite a while ago. I predominantly worked on writing the analysis. Here's the abstract from our paper for a little background:

## Abstract

Using random sampling to filter a trace cache should provide similar results to filtering based on the "hot/cold" trace principle due to the fact that hot traces occur more often. Based primarily on the work of Behar, Mendelson, and Kolodny, we have implemented such a trace cache using the [SimpleScalar](http://www.simplescalar.com/) tool set and analyzed the results with regard to performance. Despite some unexpected results, our data was still in line with that of the prior work and showed a slight improvement over not using a trace cache. We suggest further improvements that could be made upon the trace cache structure in light of the performance benefits and low cost of implementing a random sampling filter.
