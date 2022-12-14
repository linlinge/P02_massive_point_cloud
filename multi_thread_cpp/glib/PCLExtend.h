#pragma once
#include <iostream>
#include <pcl/point_types.h>
#include <pcl/io/ply_io.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/features/normal_3d.h>
#include <pcl/surface/gp3.h>
#include <pcl/octree/octree.h>
#include <pcl/point_cloud.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/segmentation/conditional_euclidean_clustering.h>
#include <pcl/features/moment_of_inertia_estimation.h>
#include <pcl/segmentation/region_growing.h>
#include <pcl/sample_consensus/ransac.h>
#include <pcl/sample_consensus/sac_model_plane.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/filters/voxel_grid.h>

#include <omp.h>
#include <vector>
#include "V3.hpp"
#ifndef PointType
#define PointType pcl::PointXYZRGBNormal
#endif
using namespace std;
double ComputeMeanDistance(const pcl::PointCloud<PointType>::ConstPtr cloud);
double ComputeMaxDistance(const pcl::PointCloud<PointType>::ConstPtr cloud);
void TransformPointCloud(pcl::PointCloud<PointType>::Ptr cloud, pcl::PointCloud<PointType>::Ptr cloud_tf,Eigen::Affine3f tf);
vector<double> StatisticNearestDistance(const pcl::PointCloud<PointType>::ConstPtr cloud);
double GetCellSize(pcl::PointCloud<PointType>::Ptr cloud, int level);
double GetBoxMin(pcl::PointCloud<PointType>::Ptr cloud);

/* Algorithm Section */
vector<int> LoOP(pcl::PointCloud<PointType>::Ptr cloud_in, int K=45, double thresh=0.8);
void RecoverColor(pcl::PointCloud<PointType>::Ptr cloud_without_color,pcl::PointCloud<PointType>::Ptr cloud_with_color);
void subtract_points(pcl::PointCloud<PointType>::Ptr cloud, const vector<int>& indices, bool flag=false);
void FindCorrespondingIndices(pcl::search::KdTree<PointType>::Ptr kdtree, pcl::PointCloud<PointType>::Ptr acloud, vector<int>& indices);

/* some pts find its corresponding idx in another point cloud */
void idx_convert(pcl::PointCloud<PointType>::Ptr rpc, vector<int>& ridx, pcl::PointCloud<PointType>::Ptr tpc,
                 pcl::search::KdTree<PointType>::Ptr kdtree_of_tpc, vector<int>& tidx);
void idx_convert(pcl::PointCloud<PointType>::Ptr rpc, pcl::PointCloud<PointType>::Ptr tpc,
                 pcl::search::KdTree<PointType>::Ptr kdtree_of_tpc, vector<int>& tidx);

/* Eigenvalue*/                 
vector<double> get_eigenvalue(pcl::PointCloud<PointType>::Ptr cloud);
vector<double> get_length_in_each_dimension(pcl::PointCloud<PointType>::Ptr cloud);

void RemoveNan(pcl::PointCloud<PointType>::Ptr cloud);

vector<float> get_size_with_AABB(pcl::PointCloud<PointType>::Ptr cloud);
vector<float> mget_size_with_AABB(pcl::PointCloud<PointType>::Ptr cloud);
vector<float> get_size_with_OBB(pcl::PointCloud<PointType>::Ptr cloud);

double GetMEval(pcl::PointCloud<PointType>::Ptr local_cloud);